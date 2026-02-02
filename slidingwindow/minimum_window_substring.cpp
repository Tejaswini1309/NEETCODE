class Solution {
public:
// here we have to use a dynamic sliding window , we first traverse ( increment 
// right pointer ) until we get to a point where our substring satisfies the cond
// that is every element of t is present in the current substring , we check this 
// by first traversing the whole unordered map ( u1 ) the f map of t , and check
// if corresponding frequencies in u ( s ) are greater or equal if this satisfies
// for all elements of t we enter the while loop where we move our left pointer
// ( shrink the window ) until we encounter a case where the freq of some element
// is not fullfilled , we check that by seeing if by increatmenting l are we leaving
// an element somewhere , in that case we exit the while and increment r till we find
// a vaild substring again , and during this process we also note down the indices
// corresponding to the smallest substring

// we should output "" in two cases one when all elements of t are present in s , even
// once , for that we check the size of u1 and u , if they exist but frequency does
// not satisfy then they would have never entered the while loop so mins remains INT_MAX

// so hence => traverse r till valid substring is found 
// => shrink substring until it breaks
// => repeat 
    string minWindow(string s, string t) {
        int m = t.size();
        int n = s.size();
        unordered_map<char,int>u1;
        for(int i=0;i<m;++i){
                u1[t[i]]=0;
        }
        for(int i=0;i<m;++i){
                u1[t[i]]++;
        }
        unordered_map<char,int>u;
        for(int i=0;i<n;++i){
                if(u1.find(s[i])!=u1.end()){
                        u[s[i]]=0;
                }
        }
        if(u1.size()!=u.size()){
                return "";
        }
        int l=0;
        int r=0;
        int mini=0;
        int minj=0;
        int mins=INT_MAX;
        int have=0;
        while(r<n){
             if(u1.find(s[r])!=u1.end()){
                u[s[r]]++; 
             }
             int k=0;
             bool c = false;
             for(auto ptr : u1){
                char key = ptr.first;
                if(u1[key]<=u[key]){
                     k++;   
                }
             }
             if(k==u1.size()){
                c=true;
             }
             while(c){
                if(r-l+1<mins){
                        mins=r-l+1;
                        mini=l;
                        minj=r;
                }
                if(u.find(s[l])!=u.end()){
                        u[s[l]]--;
                        if(u[s[l]]<u1[s[l]]){
                                c=false;
                        }
                }
                l++;
             }
             r++;
        }
        if(mins==INT_MAX){
                return "";
        }
        string x="";
        for(int i=mini;i<=minj;++i){
                x+=s[i];
        }
        return x;
    }
};