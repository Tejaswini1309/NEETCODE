class NumMatrix {
public:
// this problem is related to prefix sum method , in nummatrix 
// we initialise a matrix pref which at index i,j contains the sum of
// elements in the rectangle from 0,0 to i,j ; for that we add each
// element to the element above it and the element to the left of it
// but if i,j >0 we would be adding a few elements twice those would
// be elements of the rectangle from 0,0 to i-1,j-1 so we subtract that
// in that case , to calculate the sum for the given vertices
// we first add the sum of elements of the rect from 0,0  to row2,col2
// to ans then if row1 is >1 => there would be some space above row1 which
// should be removed that is of rect from 0,0 to row-1,col2 similarly
// if col1 is >0 then remove the excess area row2,col1-1 , but if both
// are greater than zero we would be removing the area of rect row1,col1
// twice => we are removing that amount of area from our required region
// so we will readd that 
vector<vector<int>>pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        pref=matrix;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(i>0){pref[i][j]+=pref[i-1][j];}
                if(j>0){pref[i][j]+=pref[i][j-1];}
                if(i>0 && j>0){pref[i][j]-=pref[i-1][j-1];}
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=pref[row2][col2];
        if(row1>0){
            ans-=pref[row1-1][col2];
        }
        if(col1>0){
            ans-=pref[row2][col1-1];
        }
        if(row1>0 and col1>0){
            ans+=pref[row1-1][col1-1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */