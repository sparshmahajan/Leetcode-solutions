class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        int toparea = dfs(row-1,col,grid);
        int bottomarea = dfs(row+1,col,grid);
        int leftarea = dfs(row,col-1,grid);
        int rightarea = dfs(row,col+1,grid);
        return 1 + toparea + bottomarea + leftarea + rightarea;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    ans = max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};