class Solution {
public:
// to get a optimal solution for this problem we try to put max 
// people possible in the boat , here the limit is 2 , if a single
// persons weight itself is equal to limit then we cannot add anyone else
// that peson alone gets on the boat so only j-- in that case , else
// if his weight does not exeed limit we try to see if we can put in one
// more person , so we have to start checking it from the min weight 
// we have , if they both can go together we add them in one boat 
// so j-- and i++ both , else we just put the heavy person , here 
// yeah many other combinations maybe possible , but this is the most 
// optimal here , if the heaviest person can sit with the second 
// lightest person that means the second heaviest can also sit with him
// so its ok if we push the heaviest with the lightest even if other 
// combinations are possible 
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        int num=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                num++;
                i++;
                j--;
            }
            else{
                num++;
                j--;
            }
        }
        return num;
    }
};