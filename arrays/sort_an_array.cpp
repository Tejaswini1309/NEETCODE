class Solution {
public:
// quick sort using lomuto partition , taking last element as pivot , putting it in
// itr req position , by keeping count of elements less than pivot , repeating this
// process for the subarrays below and above the pivots , quicksort cuz it has the 
// least space complexity , it does it inplace the only space taken will be for funciton call
// stacks , and time complexity is O(nlogn)
    int partition(vector<int>&n , int low , int high){
        int pivot = n[high];
        int i=low-1;
        int j=low;
        while(j<high){
            if(n[j]<pivot){
                i++;
                swap(n[i],n[j]);
            }
            j++;
        }
        swap(n[i+1],n[j]);
        return i+1;
    }
    void qs(vector<int>&n,int low , int high){
        int pi = partition(n,low,high);
        if(low<high){
            qs(n,low,pi-1);
            qs(n,pi+1,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};