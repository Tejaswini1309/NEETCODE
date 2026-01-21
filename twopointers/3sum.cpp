class Solution {
public:
// this problem if sorted is again similar to finding two elements with a given sum , 
// we first sort the vector , and for each element in nums we check if there
// exits two other elements not including itself which add up to -1*itself , so that 
// the total sum ends up being 0 , we check that using two pointer approach , for every 
// element we check for we initialise two pointers one pointing to the start and one to the end , 
// and we keep checking the sum if its more than required we move the end inwards else
// we move the start forward , we ensure that the same triplets are not repeated 
// by sorting each vector before pushing it inside ans , and nothing the unique ones in fans
// also we ensure not to use the same elements in the vector by making sure start and end
// arent same and they are never equal to i the element we are checking for 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;++i){
            int sum = -1*nums[i];
            int start =0;
            int end = n-1;
            while(start<n and end<n and start<end){
                if(start==i){
                    start++;
                    continue;
                }
                if(end == i){
                    end--;
                    continue;
                }
                if(nums[start]+nums[end]<sum){
                    start++;
                }
                else if(nums[start]+nums[end]>sum){
                    end--;
                }
                else{
                    v.push_back(nums[i]);
                    v.push_back(nums[start]);
                    v.push_back(nums[end]);
                    sort(v.begin(),v.end());
                    ans.push_back(v);
                    v.clear();
                    start++;
                    end--;
                }

            }
        }
        int N = ans.size();
        vector<int>z(1,0);
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
        vector<vector<int>>fans;
        for(int i=0;i<N;++i){
            if(ans[i]!=z){
                fans.push_back(ans[i]);
            }
        }
        return fans;
    }
};