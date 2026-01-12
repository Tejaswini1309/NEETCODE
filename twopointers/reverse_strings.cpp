class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        // we just have to swap the elements , last with first , and so on moving 
        // inward
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};