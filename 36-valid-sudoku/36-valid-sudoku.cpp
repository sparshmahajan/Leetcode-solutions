class Solution {
public:
    bool isValid(int row,int col,char ch,vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            if(i != col)
            if(board[row][i] == ch)
                return false;
            
            if(i != row)
            if(board[i][col] == ch)
                return false;
            
            if(3 * (row/3) + i/3 != row && 3 * (col/3) + i%3 != col)
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch)
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    if(!isValid(i,j,ch,board)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};