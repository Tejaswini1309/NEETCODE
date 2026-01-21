class Solution {
public:
// for this we first calculate the number of unique numbers we have then as we traverse
// through the array if we encounter an element which is equal to its previous we swap it
// with the next element which is greater than itself and cuz of this we will encounter
// a few cases where the next element is actually less than the current we will swap in that case too
// we will stop this after we pass the kth index
    int removeDuplicates(vector<int>& nums) {
        vector<int>v(201,0);
        int n = nums.size();
        int k=0;
        for(int i=0;i<n;++i){
            if(v[nums[i]+100]==0){
                k++;
                v[nums[i]+100]=1;
            }
        }
        for(int i=0;i<n;++i){
            if(i==k){
                break;
            }
            if(i<n-1 and nums[i]>=nums[i+1]){
                int start = i;
                while(start<n and nums[start]<=nums[i]){
                    start++;
                }
                swap(nums[start],nums[i+1]);
            }
            
        }
        return k;
    }
};