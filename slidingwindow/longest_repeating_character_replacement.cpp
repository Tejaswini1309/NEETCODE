class Solution {
public:
// here we maintain a dynamic window , we check if the size of window - the max f 
// is <=k or not , since for given k elements if x of them are same then if we 
// convert all the remaining k-x elements into the x same elements itself then we 
// can do k-x more conversions , so for any interval the min number of conversions
// required are the interval length - the max frequency of an element observed
// in that interval , so we increment i (traverse)until i-j+mf+1 is >k once it
// hits that mark we shrink the interval , removing the occourance of the elements 
// we are skipping now 
    int characterReplacement(string s, int k) {
        vector<int>v(26,0);
        int n = s.size();
        int mf=1;
        int i=0;
        v[s[i]-'A']++;
        int j=0;
        int res=0;
        while(j<n and i<n){
            
            while(i<n and i-j-mf+1 <= k){
                res = max(res,i-j+1);
                i++;
                v[s[i]-'A']++;
                for(int l=0;l<26;++l){
                    mf = max(mf,v[l]);
                }
            }
            v[s[j]-'A']--;
            j++;
        }
        return res;
    }
};