class Solution {
public:
// as we keep traversing the array we add them into the map , with their
// index , for every node we encounter we check if if it already
// exists and if it does whats the diff between then if its greater
// than k or does not exit we update it to the current index , 
// but there is an other way to do this , since we need a sliding window
// aproach we could use a set in which as we traverse we 
// push our elements into it we keep checking if we encounterd a similar
// element if the set size comes to k then we remove the first element of the array
// from the set , since its no longer in reach and keep repeating the same
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>u;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(u.count(nums[i])){
                if(i-u[nums[i]]<=k){
                    return true;
                }
            }
            u[nums[i]]=i;
        }
        return false;
    }
};