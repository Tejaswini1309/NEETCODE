class Solution {
public:
// here to find the k closest elements , we calculate the mean of 
// the distance of k elements from x , and these k elements are
// contiguous as they are sorted , if we consider randomly we would
// just increase the distance , for each subarray we check we also
// store the starting and ending indices of the subarray with the 
// least mean encountered until now , an edge case would be when 
// the mean is same cuz its int , but the values might not actually 
// be equal as we just get the step of the division here , hence 
// we also store the reminder corresponding to the least min 
// so that if the means are equal for diff subarrays then we compare their
// reminders , and we store the result of the case with the least 
// reminder cuz that corresponds to lesser mean 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans(k,0);
        int n = arr.size();
        int mini=0;
        int minj=0;
        int i = 0;
        int j = k-1;
        int mean=0;
        int sum=0;
        for(int l=0;l<k;++l){
            sum+=abs(arr[l]-x);
        }
        mini=i;
        minj=j;
        int rem=0;
        mean = sum/k;
        rem = sum%k;
        int minrem=rem;
        int minmean=mean;
        while(j<n-1){
            i++;
            sum=sum-abs(arr[i-1]-x);
            j++;
            sum=sum+abs(arr[j]-x);
            mean = sum/k;
            rem = sum%k;
            if(minmean>mean){
                minmean = mean;
                mini=i;
                minj=j;
                minrem=rem;
            }
            else if(minmean==mean){
                if(minrem<=rem){
                    continue;
                }
                else{
                    minmean = mean;
                    mini=i;
                    minj=j;
                    minrem=rem;
                }
            }
            else{
                continue;
            }
        }
        int ind=0;
        for(int l=mini;l<=minj;++l){
            ans[ind]=arr[l];
            ind++;
        }
        return ans;
    }
};