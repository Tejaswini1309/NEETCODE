class Solution {
public:
// if the stack is empty we add an asteroid to the stack , if the next
// a is in the same direction they will not collide , if they are 
// moving in opp directions and only if they are moving towards each other
// that is earlier right new left we check for the following cases else , 
// we just add them , if they are moving towards each other and they 
// are equal in sizes we remove the previous one and move to the next 
// asteroid , if the one already present is bigger than the one coming 
// we do not add the incoming one , it gets shattered and we skip to 
// the next one , if none of these if the previous one is smaller than 
// the incoming one then we keep removing such a either until the stack is 
// empty or we find one in same direction 
    vector<int> asteroidCollision(vector<int>& a) {
        int n= a.size();
        stack<int>s;
        for(int i=0;i<n;++i){
            if(s.empty()){
                s.push(a[i]);
                continue;
            }
            if(s.top()*a[i]>0){
                s.push(a[i]);
            }
            else if(s.top()<0 and a[i]>0){
                s.push(a[i]);
            }
            else{
                while(s.empty()!=true){
                    if(s.top()*a[i]>0){
                        s.push(a[i]);
                        break;
                    }
                    if(s.top()<abs(a[i])){
                        s.pop();
                        if(s.empty()){
                            s.push(a[i]);
                            break;
                        }
                    }
                    if(s.top()==abs(a[i])){
                        s.pop();
                        break;
                    }
                    if(s.top()>abs(a[i])){
                        break;
                    }
                }
            }
        }
        int N = s.size();
        vector<int>v(N,0);
        for(int i=N-1;i>=0;--i){
            v[i]=s.top();
            s.pop();
        }
        return v;
    }
};