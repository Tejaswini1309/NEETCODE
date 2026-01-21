class Solution {
public:
// its just merging two arrays but we will not put them in a new 
// array but withing the first one itself for that whenever we 
// encounter a smaller element in nums2 and it should be put 
// among the valid elements we need to shift all of the elements
// from that position to one position to the right , end keeps 
// track of the earliest 0 , and if incase we ran out of all the 
// valid elements of nums1 and are left with the elements of nums2 
// then we just add them after exiting the original loop , to exit 
// we check if the current is 0 and the prev in nums1 is less than the
// current in nums2 , this shows we finished traversing through nums1 
// elements 
    void shift(vector<int>&n,int start,int end){
        for(int i=end-1;i>=start;--i){
            n[i+1]=n[i];
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int  end = m;
        int start=0;
        while(i<m+n and j<n){
            if(i==end and nums1[i-1]<nums2[j]){
                break;
            }
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                start = i ;
                shift(nums1,start,end);
                end++;
                nums1[i]=nums2[j];
                j++;
            }
        }
        while(end!=m+n){
            nums1[end]=nums2[j];
            end++;
            j++;
        }

    }
};