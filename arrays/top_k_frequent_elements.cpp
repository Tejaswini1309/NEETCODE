class Solution {
public:
// here we first create a hash map to store frequencies , so at
// index nums[i]+1000 you will have the frequency of nums[i]
// then we use a vector of vectors bucket where the index would be
// frequency and the corresponding vector will consist of elements with
// that frequency , we traverse through v and using v[i] as index 
// pushback the i-1000 , as we hashed it before and to do this
// we have to declare the size of buckets , the max frequency of any 
// element could be n the size of nums and the max size of nums
// is 10000 hence its size is 10001 , then we traverse buckets from last
// to acess the elemets with highest frequencies and psuh them into ans
// once ans size reaches k we eexit the loop and return ans 
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int>v(2001,0);
      vector<vector<int>>bucket(10001);
      vector<int>ans;
      int n = nums.size();
      for(int i=0;i<n;++i){
        v[1000+nums[i]]++;
      }
      for(int i=0;i<2001;++i){
        if(v[i]==0){
            continue;
        }
        else{
            bucket[v[i]].push_back(i-1000);
        }
      }
      for(int i=10000;i>=0;--i){
        if(!bucket[i].empty()){
            for(int j=0;j<bucket[i].size();++j){
                if(ans.size()==k){
                    break;
                }
                ans.push_back(bucket[i][j]);
            }
        }
      }
      return ans;
    }
};