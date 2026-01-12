class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int x=0;
        if(n==0){
            return 0;
        }
        // whenever we encounter val we search for the next element which is not vla and swap with it 
        // as a result after the loop terminates all the values of val will be at the end of the array 
        // and we just traverse through the array and find the value of k , that is number of elements before the first val appears 
        for(int i=0;i<n;++i){
            if(nums[i]==val){
                for(int j=i+1;j<n;++j){
                    if(nums[j]!=val){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]==val){
                x++;
            }
        }
        return n-x;
    }
};