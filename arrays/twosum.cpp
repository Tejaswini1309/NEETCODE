class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>u;
        int n = nums.size();
        for(int i=0;i<n;++i){
            u[nums[i]]=0;
        }
        vector<int>v(2,0);
        int x=0;
        // for every element of nums we check if target-the element exist or not 
        // if it exists we iterate through the left over num and find the index , and also we start the traversal from i+1 to avoid dublicates (i.e, if target = 2*the element)
        for(int i=0;i<n;++i){
            x = target-nums[i];
            if(u.find(x)!=u.end()){
                v[0]=i;
                for(int j=i+1;j<n;++j){
                    if(nums[j]==x){
                        v[1]=j;
                        return v;
                    }
                }
            }
        }
    }
};