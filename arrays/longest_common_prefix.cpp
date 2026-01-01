class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string x=strs[0];
        int n=strs.size();
        // we start comparing x with the second element of strs , while comparing we maintain a string 'a' which is the common prefix of x and the current element of strs , we update x to a after every such comparision and hence after iterating through the whole loop we find x to be the longest common prefix the time complexity stays o(n) as the max length of string inside strs is 200 and max time complexity would be n*200 hence o(n)
        for(int i=1;i<n;++i){
            int n1=strs[i].length();
            int n2=x.length();
            int y = min(n1,n2);
            string a="";
            for(int j=0;j<y;++j){
                if(x[j]==strs[i][j]){
                    a+=x[j];
                }
                else{
                    break;
                }
            }
            x = a;
            if(x == ""){
                return "";
            }
        }
        return x;
    }
};