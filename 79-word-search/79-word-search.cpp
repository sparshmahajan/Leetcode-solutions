class Solution {
public:
    bool isValid(int i,int j,vector<vector<char>>& board){
        if(i >=0 and j>=0 and i < board.size() and j < board[0].size())
            return true;
        return false;
    }
    
    void dfs(int i,int j,vector<vector<char>>& board,vector <vector<int>>& freq,string word,int p,bool& flag){
        if(flag) return;
        
        if(freq[i][j]) return;
        
        freq[i][j] = 1;
        
        if(p == word.length()-1){
            flag = true;
            return;
        }
        
        if(isValid(i-1,j,board) && board[i-1][j] == word[p+1])
            dfs(i-1,j,board,freq,word,p+1,flag);
        
        if(isValid(i+1,j,board) && board[i+1][j] == word[p+1])
            dfs(i+1,j,board,freq,word,p+1,flag);
        
        if(isValid(i,j-1,board) && board[i][j-1] == word[p+1])
            dfs(i,j-1,board,freq,word,p+1,flag);
        
        if(isValid(i,j+1,board) && board[i][j+1] == word[p+1])
            dfs(i,j+1,board,freq,word,p+1,flag);
        
        freq[i][j] = 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector <vector<int>> freq(board.size() , vector <int>(board[0].size(),0));
        bool flag = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(flag)
                    break;
                if(board[i][j] == word[0])
                    dfs(i,j,board,freq,word,0,flag);
            }
            if(flag)
                break;
        }
        return flag;
    }
};