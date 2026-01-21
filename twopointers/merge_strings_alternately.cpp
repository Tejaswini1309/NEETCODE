class Solution {
public:
// we just keep adding them alternatively and add the chars of left over 
// string at last 
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        string s;
        int i=0;
        int j=0;
        while(i<n and j<m ){
            s+=word1[i];
            i++;
            s+=word2[j];
            j++;
        }
        while(i<n){
            s+=word1[i];
            i++;
        }
        while(j<m){
            s+=word2[j];
            j++;
        }
        return s;
    }
};