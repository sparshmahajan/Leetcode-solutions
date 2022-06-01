class Solution {
public:
    void solve(int col,int n,vector<string>& board,int& count,vector <int> leftRow,vector <int> upperDiagonal,vector <int> lowerDiagonal){
        if(col == n){
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col-row]=1;
                solve(col+1,n,board,count,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1 + col-row]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int count=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector <int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        solve(0,n,board,count,leftRow,upperDiagonal,lowerDiagonal);
        return count;
    }
};