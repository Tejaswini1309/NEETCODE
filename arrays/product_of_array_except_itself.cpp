class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        vector<int>right(n,1);
        int prod=1;
        for(int i=n-1;i>=0;--i){
            right[i]*=nums[i];
            if(i!=n-1){
                right[i]*=right[i+1];
            }
        }
        for(int i=0;i<n;++i){
            if(i<n-1){
            ans[i]=right[i+1]*prod;
            }
            else{
                ans[i]=prod;
            }
            prod*=nums[i];
        }
        return ans;
    }
};
