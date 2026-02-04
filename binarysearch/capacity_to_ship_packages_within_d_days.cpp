class Solution {
public:
// its same like the koko eating bananas problem but here you will check the load value
// min load should be such that you can put in the heaviest package on the conveyer 
// and max would be when days = 1 you should be able to put all the packages inside in
// one day so max is sum of all the weights , between these min and max we have to
// find the least value with which we can ship within least number of days so we 
// apply binary search again among those values if we are taking more than days 
// we have to increment our daily load else we store the possible solution and
// keep checking for lower values
    int Days(vector<int>&w , int days , int m){
        int ans =0;
        int sum =0;
        int n = w.size();
        for(int i=0;i<n;++i){
            sum+=w[i];
            if(sum==m){
                ans++;
                sum=0;
                continue;
            }
            else if(sum>m){
                sum = w[i];
                ans++;
            }
            if(i==n-1 and sum<m){
                ans++;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        int end = 0;
        for(int i=0;i<weights.size();++i){
            start = max(start , weights[i]);
            end +=weights[i];
        }
        int ans =0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(Days(weights , days , mid) > days){
                start = mid+1;
            }
            else{
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};