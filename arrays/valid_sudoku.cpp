class Solution {
public:
// for this we first check if each column and row for any dublicateelements
// if they are present we return false , later we check for 3X3 squares
// we first check all 3 of the first 3 columns and so on , for that we 
// use the function square 
    bool square(vector<vector<char>>& board,vector<int>sq,int r,int c){
        for(int i=r*3;i<3*(r+1);++i){
            for(int j=c*3;j<3*(c+1);++j){
                if(board[i][j]=='.'){
                    continue;
                }
                if(sq[board[i][j]-'0']!=0){
                    return false;
                }
                sq[board[i][j]-'0']++;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>row(10,0);
        vector<int>col(10,0);
        vector<int>sq(10,0);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    continue;
                }
                if(row[board[i][j]-'0']!=0){
                    return false;
                }
                row[board[i][j]-'0']++;
            }
            fill(row.begin(), row.end(), 0);
        }
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[j][i]=='.'){
                    continue;
                }
                if(col[board[j][i]-'0']!=0){
                    return false;
                }
                col[board[j][i]-'0']++;
            }
            fill(col.begin(), col.end(), 0);
        }
        int r=0;
        int c=0;
        while(r<3){
            while(c<3){
            if(square(board,sq,r,c)){
                c++;
            }
            else{
                return false;
            }
            }
            r++;
            c=0;
        }
        return true;
    }
};