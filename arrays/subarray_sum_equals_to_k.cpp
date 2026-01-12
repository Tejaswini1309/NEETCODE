class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>s;
        int sum=0;
        int n = nums.size();
        int ans=0;
        // for this problem we keep adding the elements of the array
        // if the sum until then is y then suppose y-x=k; x can be +ve or
        // -ve , then x the number which we require is y-k; since wht we
        // are inserting into the map is nothing but the value of sum of 
        // elements of the subarray starting from the first element and 
        // ending at diff indexes , so for some index j we have the sum from 
        // the 0th index to the jth element , we need to find if a x exists before
        // this or not that means does a subarray from the 0th element exist with its 
        // sum as x , if yes , then we remove that subarray and we have a subarray 
        // with sum as k , also one exception is if an element itself is equal to k
        // in that case it will search for 0 if there is no zero it will not consider
        // that element hence we must also consider that case , in either cases
        // whether zero is present or not 
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(s.find(sum-k) != s.end()){
                ans+=s[sum-k];
            }
            if(sum==k){
                ans++;
            }
            if(s.find(sum)==s.end()){
                s[sum]=1;
            }
            else{
                s[sum]++;
            }
            
        }
        return ans;
    }
};