class Solution {
public:
// we check each operation and perform the functions , in '+' we 
// remove the top element to access the one below it and readd it later 
// along with the new score 
    int calPoints(vector<string>& operations) {
        stack<int>s;
        int n = operations.size();
        for(int i=0;i<n;++i){
            if(operations[i] =="+"){
                if(s.empty() || s.size()==1){
                    continue;
                }
                int temp1 = s.top();
                s.pop();
                int temp = s.top();
                s.push(temp1);
                s.push(temp+temp1);
            }
            else if(operations[i]=="D"){
                s.push(2*s.top());
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else{
                s.push(stoi(operations[i]));
            }
        }
        int ans=0;
        while(s.empty()!=true){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};