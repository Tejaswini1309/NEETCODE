class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        int n = numbers.size();
        int i=0;
        int j=n-1;
        // we initialise two indexes one to the last element and one 
        // to the first element if their sum is less than required target
        // we will increment i ( incerasing the number as its a non decreasing array )
        // else if its less we will decrement j and since they said there
        // will always be a solution and i!=j , i will be equal to j only if
        // there was no solution found before that condition is met
        // but we do know that a solution exists 
        while(true){
            if(numbers[i]+numbers[j] < target){
                i++;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            if(numbers[i]+numbers[j]==target){
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
        }
    }
};