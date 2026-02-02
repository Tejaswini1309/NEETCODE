class Solution {
public:
// here we determine if a car crosses the other by checking the amount of time 
// in which they will reach the target , first we sort them wrt their initial positions
// here we solve the problem from the end , if one car has to form a fleet with its next
// its time required must be less than or equal to the speed of car infront of it 
// and even if it takes less time by its own the time by which it will reach
// the target remains same thats the time taken by the car infront as later
// any car that forms a fleet with this car will atain its speed , so if 
// and only if the car infront of a car forms a fleet with the car infront 
// the third car will not form a fleet no mater what the speed is as 
// once it comes near the second car it will gain its speed , so we traverse from the 
// back x is the time which the fleet above will take to reach target iff the
// time taken by the car behind is less or equal to x it will not be a part of fleet
// if its not a part of fleet ( that is if we are updating x ) that means we are 
// starting a new fleet hence we update our count 
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<float>s;
        unordered_map<int,int>u;
        for(int i=0;i<n;++i){
            u[position[i]]=speed[i];
        }
        sort(position.begin(),position.end());
        for(int i=0;i<n;++i){
            float t = (target-position[i])/static_cast<float>(u[position[i]]);
            s.push(t);
        }
        float x = s.top();
        s.pop();
        int c = 1;
        while(!s.empty()){
            if(x<s.top()){
                x = s.top();
                c++;
            }
            s.pop();
        }
        return c;
    }
};