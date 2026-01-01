class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>u;
        // counting frequencies and returning the one with frequency greater than n/2
        for(int i=0;i<n;++i){
            u[nums[i]]=0;
        }
        for(int i=0;i<n;++i){
            u[nums[i]]++;
        }
        for(int i=0;i<n;++i){
            if(u[nums[i]] > n/2){
                return nums[i];
            }
        }
    }
};