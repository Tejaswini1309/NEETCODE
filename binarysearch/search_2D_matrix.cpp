class Solution {
public:
// binary search itself but on all the rowns until you find the element or you return 
// false
    bool binarysearch(int target ,vector<vector<int>>& matrix , int m , int n){
       int s = 0;
       int e = n;
       int mid=0;
       while(s<=e){
        mid = (s+e)/2;
        if(matrix[m][mid]==target){
            return true;
        }
        else if(matrix[m][mid]<target){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
       }
       return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int x =0;
        while(x<row){
            if(binarysearch(target , matrix , x , col-1)){
                return true;
            }
            else{
                x++;
            }
        }
        return false;
    }
};
