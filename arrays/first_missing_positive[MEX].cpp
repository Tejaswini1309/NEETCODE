class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>v(100002,0);
        int n = nums.size();
        // according to the given constraints the max length of the array nums is 100000
        // so the maximum value of the MEX must be 100001 considering all numbers from 1 to 100000 are present
        // so we create a hash table for storing the occourance elements in nums (well they are frequencies) 
        // then we traverse the hash table from index 1 to 100001 whereever the frequency is 0 first that is our MEX value 
        // as thats the least positive integer that hasnt appeared in the array nums and negative values are ignored similar to values greater than 100000
        for(int i=0;i<n;++i){
            if(nums[i]<100002 and nums[i]>0){
                v[nums[i]]++;
            }
        }
        int x=0;
        for(int i=1;i<100002;++i){
            if(v[i]==0){
                x=i;
                break;
            }
        }
        return x;
    }
};