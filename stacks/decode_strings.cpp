class Solution {
public:
// here we keep adding the elements we encounter in the string s into the stack st , 
// when we encounter the char ']' we stop and pop the elements in the stack storing them
// in a string temp until we encounter '[', that is we are storing the string we have
// to repeat k number of times , to get k we first pop the '[' then k can actually be 
// more than 9 too for that we keep poppint until we are done with the numbers in it 
// we maintain a variable d to keep count fo the required base of 10 , we pop the 
// numbers simultaneously and then add the string temp ( push ) to the stack count 
// number of times , and also the string which we have in our temp will be in reverse 
// order as stack is last in first out , so the first element of the string will be our
// last in the temp string , edge cases to note are if the given string starts with a number
// we will get segmentation fault if we just check the ascii values in while loop statement
// we must also note when the stacks turns empty and.. avoid double adding if empty 
// we just add once do not forget continue or use else ifs 
    string decodeString(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;++i){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]==']'){
                string temp="";
                while(st.top()!='['){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                int count = 0;
                int d =1;
                while(st.size()!=0 and st.top()-'0'<=9 and st.top()-'0'>=0){
                    count+=(st.top()-'0')*d;
                    st.pop();
                    d*=10;
                }
                d=1;
                int N = temp.size();
                while(count){
                    for(int j=N-1;j>=0;--j){
                        st.push(temp[j]);
                    }
                    count--;
                }
            }
            else{
                st.push(s[i]);
            }
        }
        int m = st.size();
        string ans(m,'0');
        for(int i=m-1;i>=0;--i){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};