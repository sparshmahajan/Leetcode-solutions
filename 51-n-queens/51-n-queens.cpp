class Solution {
public:
//     bool isQueenSafe(vector <string> board,int row,int col,int n){
//         //for upper digonal
//         int duprow = row;
//         int dupcol = col;
//         while(row >=0 && col >= 0){
//             if(board[row][col] == 'Q') return false;
//             row-- , col--;
//         }
        
//         //for lower digonal
//         row = duprow;
//         col = dupcol;
//         while(row < n and col >= 0){
//             if(board[row][col] == 'Q') return false;
//             row++, col--;
//         }
        
//         //for left side
//         row = duprow;
//         col = dupcol;
//         while(col >= 0){
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }
//         return true;
//     }
    
    void solve(int col,int n,vector<string>& board,vector <vector<string>>& ans,vector <int> leftRow,vector <int> upperDiagonal,vector <int> lowerDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col-row]=1;
                solve(col+1,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 + col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector <vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector <int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        solve(0,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};