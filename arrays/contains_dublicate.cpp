class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>u;
        int n = nums.size();
        for(int i=0;i<n;++i){
            u[nums[i]]=0;
        }
        for(int i=0;i<n;++i){
            u[nums[i]]++;
        }
        for(int i=0;i<n;++i){
            if(u[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};