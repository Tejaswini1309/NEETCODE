class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minimum=prices[0];
        int n=prices.size();
        for(int i=1;i<n;++i){
            if(prices[i]<=minimum){
                minimum=prices[i];
            }
            else{
                profit+=prices[i]-minimum;
                minimum=prices[i];
            }
        }
        return profit;
    }
};