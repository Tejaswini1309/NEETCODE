class Solution {
public:
// so here our task is that we must make sure that there are no contiguos '/'
// and no '..' or '.' , for the first condition we will check if the
// top and curr are equal to '/' if yes then we skip the curr , 
// if its a dot then until we find some other char we keep calculating
// the number of dots , we store it in dc , i will then be pointing 
// to the last dot , if we have more than 2 we just add them all into
// the stack , but if they are 2 / 1 we have to check if they end 
// with a / ( or are the last ones in the string that is i is n-1) as
// in those cases they are part of the directories name and we just push
// them into the string as usual but if they arent and if dc = 1
// we just skip the dot and move to the next chars as it
// indicates current directory else if dc = 2 , we must remove the 
// previous directory so first we pop the '/' which is the top of 
// stack and keep popping until we encounter another '/' and again if
// the only element is '/' we will not remove it , also we must make 
// sure that if the last element is '/' we must remove it , this 
// happens when the dots we the end of the string , and then we
// store the contents of the stack into a string from the end 
    string simplifyPath(string path) {
        int n= path.length();
        int dc=0;
        stack<char>s;
        for(int i=0;i<n;++i){
            if(s.empty()){
                s.push(path[i]);
            }
            if(path[i]=='/' and s.top()=='/'){
                continue;
            }
            if(s.top()=='/' and path[i]=='.'){
                while(path[i]=='.'){
                    dc++;
                    i++;
                }
                i-=1;
                bool k = true;
                if(i+1 < n and path[i+1]!='/'){
                    k = false;
                }
                if(dc==1 and k){
                    dc=0;
                    continue;
                }
                else if(dc==2 and k){
                    if(s.size()==1){
                        dc=0;
                        continue;
                    }
                    s.pop();
                    while(s.top()!='/'){
                        s.pop();
                    }
                    dc=0;
                }
                else{
                    while(dc){
                        s.push('.');
                        --dc;
                    }
                    continue;
                }
            }
            else{
                s.push(path[i]);
            }
        }
        int m = s.size();
        if(s.size()!=1 and s.top()=='/'){
            s.pop();
            m=m-1;
        }
        string st(m,'0');
        for(int i=m-1;i>=0;--i){
            st[i]=s.top();
            s.pop();
        }
        return st;
    }
};