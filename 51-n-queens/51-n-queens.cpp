class Solution {
public:
    bool isQueenSafe(vector <string> board,int row,int col,int n){
        //for upper digonal
        int duprow = row;
        int dupcol = col;
        while(row >=0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row-- , col--;
        }
        
        //for lower digonal
        row = duprow;
        col = dupcol;
        while(row < n and col >= 0){
            if(board[row][col] == 'Q') return false;
            row++, col--;
        }
        
        //for left side
        row = duprow;
        col = dupcol;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        return true;
    }
    
    void solve(int col,int n,vector<string>& board,vector <vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isQueenSafe(board,row,col,n)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector <vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        solve(0,n,board,ans);
        return ans;
    }
};