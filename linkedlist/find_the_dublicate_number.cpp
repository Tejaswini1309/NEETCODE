class Solution {
public:
// but how can we do this using linked list ? a hash with linked list ? check that approach 
    int findDuplicate(vector<int>& nums) {
      vector<int>v(10001,0);
      int n = nums.size();
      for(int i=0;i<n;++i){
        if(v[nums[i]]!=0){
            return nums[i];
        }
        v[nums[i]]++;
      }  
    }
};
