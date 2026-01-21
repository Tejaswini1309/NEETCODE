class MinStack {
public:
stack<int>s;
stack<int>min;
int Min;
// to find the min of all elements in the stack in O(1) time you need 
// to maintain another stack which has the min of numbers encountered
// until then , but we must make sure to update the element with which we 
// are calculating the min , if the min is popped update it to the last min
// or if the min stack becomes empty reinitialise the min to int_max
    MinStack() {
         Min =INT_MAX;
    }
    
    void push(int val) {
        s.push(val);
        if(val<Min){
            min.push(val);
            Min = val;
        }
        else{
            min.push(Min);
        }
    }
    
    void pop() {
        s.pop();
        min.pop();
        if(min.empty()){
            Min = INT_MAX;
        }
        else{
            Min = min.top();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};