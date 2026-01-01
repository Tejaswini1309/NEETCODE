class Solution {
public:
    int k = 2;
    string encode(vector<string>& strs) {
       string s="";
       for(int i=0;i<strs.size();++i){
            s+=strs[i];
            s+='\0';
       }
       return s;
    }

    vector<string> decode(string s) {
        string k="";
        vector<string>v;
        for(int i=0;i<s.length();++i){
            if(s[i]=='\0'){
                v.push_back(k);
                k="";
                continue;
            }
            k+=s[i];
        }
        return v;
    }
};

