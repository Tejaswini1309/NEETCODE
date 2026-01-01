class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_map<int,int>u;
       int n = nums.size();
       if(n==0){
        return 0;
       }
       for(int i=0;i<n;++i){
        u[nums[i]]=0;
       }
       for(int i=0;i<n;++i){
        u[nums[i]]++;
       }
       int res=0;
       for(int i=0;i<n;++i){
            int res=1;
            if(u.find(nums[i]-1) == u.end()){
                int x = nums[i]+1;
                while(u.find(x)!=u.end() and u[x]!=0){
                    res++;
                    u[x]=0;
                    x+=1;
                }
            }
            nums[i]=res;
       }
       int maxi=INT_MIN;
       for(int i=0;i<n;++i){
            maxi = max(maxi,nums[i]);
       } 
       return maxi;
    }
};
