class Solution {
public:
// here we maintain two pointers left and right , and also store 
// the occourance of the chars between them in an unordered map
// if we encounter a dublicate of something we move the left until it
// passes the dublicate while doing we must also remove the
// occourances of those elements which we now skip , and set the
// occourance of the dublicate to one , and we must also note 
// the max length at each step
    int lengthOfLongestSubstring(string s) {
        int ans =0;
        int mans=0;
        unordered_map<char,int>u;
        int n = s.length();
        for(int i=0;i<n;++i){
            u[s[i]]=0;
        }
        int l = 0;
        u[s[l]]++;
        int r=1;
        if(n==1){
            return 1;
        }
        while(r<n){
            if(u[s[r]]!=0){
                while(s[l]!=s[r]){
                    u[s[l]]=0;
                    l++;
                }
                u[s[l]]=1;
                l++;
            }
            else{
                u[s[r]]++;
            }
            ans = r-l+1;
            mans = max(ans,mans);
            r++;
        }
        return mans;
    }
};