class Solution {
public:
// we use dynamic sliding window , we traverse nums until the sum>= target , if 
// that satisfies we start shrinking the window while noting the size of the window 
// we repeat this process until i reaches the end , and j follows [be careful 
// while dealing with sizes of windows with indices ] { also this only works since
// all the elements are positive so we know that if we shring the current window the 
// sum will ofc reduce}
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int res =INT_MAX;
        int sum=0;
        while(j<=i and i<n){
            while(i<n and sum<target){
                sum+=nums[i];
                i++;
            }
            while(j<=i and sum>=target){
                res = min(res,i-j);
                sum-=nums[j];
                j++;
            }
        }
        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};