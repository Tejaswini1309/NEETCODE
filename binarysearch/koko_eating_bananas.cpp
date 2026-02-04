class Solution {
public:
// the max value of k will be the max pile size , h cannot be <n it will be at max 
// n so then we need to return max value ; we now have to find an element between 
// 1 and max(piles) which satisfies h (it takes either less or equal to h hours) so
// we apply binary search with start as 1 and end as max value to find such an 
// element if we encounter a feasible element we store it in ans .
    int hour(vector<int>&p , int h , int m){
        int hou =0;
        for(int i=0;i<p.size();++i){
            hou+=p[i]/m;
            if(p[i]%m!=0){
                hou+=1;
            }
        }
        return hou;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1;
        int end = 0;
        for(int i=0;i<piles.size();++i){
            end = max(end,piles[i]);
        }
        int mid =0;
        int ans =0;
        while(start<=end){
            mid = start + (end-start)/2;
            if(hour(piles,h,mid) <= h){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};