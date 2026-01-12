class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=nums[0];
        int n=nums.size();
        // to solve this we keep track of the max sum encountered
        // until then in variable ans , and if out current sum is 
        // greater than ans we update ans , if its equal nothing changes
        // but if its less than ans the maximum length obtained till now 
        // and it is negative that means its not contributing to anything thats
        // going to come after it , it will just damage it more in that case
        // we end it there are reset sum to 0 to start counting from the next element
        // an element can be the start of the subarray or even the end of it 
        // also all the elements can be negative too so wecannot initialise 
        // ans to int_min and sum to 0 , hence we put them both as the 0th
        // index element , and if encounter a array such as -1,5 then our result
        // will be 4 if we do not add the last loop , which if it finds a element
        // which is alone greater than the max sum obtained even after adding 
        // it as the previous max sum would have been -ve from the beginning 
        // in that case we must make sure we update the max sum to that element and 
        // start a subarray with that element as the beginning well only if in a few cases
        // like -2 , -1 , 5 ,2 or just if the max sum was -ve and that was equal to the
        // last element just before the positive val 
        for(int i=1;i<n;++i){
            sum+=nums[i];
            if(sum>=ans){
                ans=sum;
            }
            if(sum < ans and sum < 0){
                sum=0;
            }
            if(nums[i]>ans){
                ans = nums[i];
                sum = nums[i];
            }
        }
        return ans;
    }
};
