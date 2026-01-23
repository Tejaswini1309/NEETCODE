class Solution {
public:
// here we first make a hash map for our s1 string using a vector , 
// since we need the permuataion of s1 in s2 it can actually be in
// any order but in contiguous , hence we will make a window of 
// size n and slide it along s2 for every window we we make a hash map
// (a vector) and check if they are the same if yes then we return true
// else we return false after traversing the whole string s2
    bool checkInclusion(string s1, string s2) {
        vector<int>v(26,0);
        vector<int>v2(26,0);
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<n;++i){
          v[s1[i]-'a']++;
        }
        int i =0;
        int j = n-1;
        while(j<m){
            for(int l=i;l<=j;++l){
              v2[s2[l]-'a']++;
            }
            if(v2==v){
              return true;
            }
            fill(v2.begin(),v2.end(),0);
            i++;
            j++;
        }
        return false;
    }
};