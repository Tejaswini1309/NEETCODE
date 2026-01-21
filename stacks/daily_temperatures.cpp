class Solution {
public:
// this is just like the inverse of checking the previous greatest element 
// we do the same thing but we just start from the end of the array 
// if we see that an element is greater than our stack top we remove everything else
// before that checking if we encounter an even larger element and push this element into the stack
// cuz firstly we add an element smaller than the top into the stack cuz 
// if we encounter an element even less than this , but if we see a greater element 
// it wont be a problem as that would still be the greater one even if we encounter a smaller 
// element later on , if we encounter larger we do the process told above 
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<int>s;
        vector<int>v(n,0);
        stack<int>ind;
        s.push(t[n-1]);
        v[n-1]=0;
        ind.push(n-1);
        for(int i=n-2;i>=0;--i){
            if(s.top()>t[i]){
                v[i]=ind.top()-i;
                s.push(t[i]);
                ind.push(i);
            }
            else{
                while(true){
                    if(s.top()>t[i]){
                        v[i]=ind.top()-i;
                        s.push(t[i]);
                        ind.push(i);
                        break;
                    }
                    else{
                        s.pop();
                        ind.pop();
                        if(s.empty()){
                            s.push(t[i]);
                            ind.push(i);
                            v[i]=0;
                            break;
                        }
                    }
                }
            }
        }
        return v;
    }
};
