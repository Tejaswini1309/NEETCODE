class Solution {
public:
// here we use a map to make a hash with key as a vector which maps to
// another vector of strings ,we cannot use unordered map as it uses
// a c++ inbuilt struct hash to map elements , but hash is defined 
// only for limited datatypes , its not defined for vectors , we
// have to define a custom hash of vectors to use it as key in unordered
// map , so we use map where the key would be the frequency vector 
// of a string in the strs vector , and as we traverse we find 
// the frequency vector of all the strings and store store them
// in the map , later we push back all the vectors in the map
// to the vector of strings ans
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int>v(26,0);
        map<vector<int>,vector<string>>u;
        vector<vector<string>>ans;
        int n = strs.size();
        for(int i=0;i<n;++i){
            int m = strs[i].length();
            for(int j=0;j<m;++j){
                v[strs[i][j]-'a']++;
            }
            u[v].push_back(strs[i]);
            fill(v.begin(),v.end(),0);
        }
        for(auto it : u){
            ans.push_back(it.second);
        }
        return ans;
    }
};