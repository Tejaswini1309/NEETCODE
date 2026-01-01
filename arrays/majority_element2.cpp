class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>u;
        vector<int>v;
        int n = nums.size();
        for(int i=0;i<n;++i){
            u[nums[i]]=0;
        }
        for(int i=0;i<n;++i){
            u[nums[i]]++;
        }
        for(int i=0;i<n;++i){
            if(u[nums[i]]> n/3){
                v.push_back(nums[i]);
                u[nums[i]]=0;
            }
        }
        return v;
    }
};