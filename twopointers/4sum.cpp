class Solution {
public:
// same as 3 sum but we make sure we dont reconsider the ith element 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;++i){
            long long int sum = target-nums[i];
            for(int j=0;j<n;++j){
                if(j==i){
                    j++;
                    continue;
                }
                long long int sum1 = sum-nums[j];
                int start=0;
                int end=n-1;
                while(start<n and end<n and start<end){
                    if(start==i || start==j){
                        start++;
                        continue;
                    }
                    if(end==i || end==j){
                        end--;
                        continue;
                    }
                    if(nums[start]+0LL+nums[end]<sum1){
                        start++;
                        continue;
                    }
                    else if(nums[start]+0LL+nums[end]>sum1){
                        end--;
                        continue;
                    }
                    else{
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[start]);
                        v.push_back(nums[end]);
                        sort(v.begin(),v.end());
                        ans.push_back(v);
                        v.clear();
                        start++;
                        end--;
                        continue;
                    }
                }
            }
        }
        if(ans.empty()){
            return ans;
        }
        vector<int>z(1,0);
        vector<vector<int>>fans;
        int N = ans.size();
        for(int i=0;i<N;++i){
            if(ans[i]==z){
                continue;
            }
            for(int j=i+1;j<N;++j){
                if(ans[j]==ans[i]){
                    ans[j]=z;
                }
            }
        }
        for(int i=0;i<N;++i){
            if(ans[i]!=z){
                fans.push_back(ans[i]);
            }
        }
        return fans;
    }
};