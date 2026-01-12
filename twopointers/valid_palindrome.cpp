class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        // just checking if  a strings reverse is equal to itself
        // but to avoid non alphanumeric variables use fn isalnum
        // if not skip it and since capital and small are equivalent
        // here check after converting them into one case either
        // lower or upper 
        while(i<=j){
           if(!isalnum(s[i])){
            i++;
           }
           else if(!isalnum(s[j])){
            j--;
           }
           else if(tolower(s[i])==tolower(s[j])){
            i++;
            j--;
           }
           else{
            return false;
           }
        }
        return true;
    }
};
