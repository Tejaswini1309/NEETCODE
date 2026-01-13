class Solution {
public:
    int trap(vector<int>& h) {
        // water will be trapped between two toweres iff the width 
        // between them is >= 1 and the elements between them must be 
        // smaller than either of them , if that condition satisfies
        // for two given towers the water amount between them would be 
        // the sum of the height of the min tower - the heights of the 
        // towers between them , hence we keep checking for the min tower
        // between the last two ends and move towards the max 
        // and count the amount of water stored there , by updating the
        // min of the two ends and calculating the water stored at each element

        int n = h.size();
        int ch=0;
        int ans = 0;
        for(int i=0, j=n-1; i<j; ){
            if(h[i] < h[j]){
                ch = max(ch, h[i]);
                ans += (ch-h[i]);
                i++;
            }
            else{
                ch = max(ch, h[j]);
                ans += ch-h[j];
                j--;
            }
        } 
        return ans;     
    }
};