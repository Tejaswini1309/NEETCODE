class Solution {
public:
    // for solution with O(n) space we just make a copy of the 
    // vector nums and assign values accordingly the last k elements as 
    // the first and the next n-k as the first n-k elements 

    // to do it inplace we reverse the whole array and then reverse the 
    // segments from 0 to k-1 and k to n-1 
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(k==0){
            return;
        }
        vector<int>copy(n,0);
        copy=nums;
        int l=0;
        for(int i=k;i<n;++i){
            nums[i]=copy[l];
            l++;
        }
        for(int i=0;i<k;++i){
            nums[i]=copy[l];
            l++;
        }
    }
};