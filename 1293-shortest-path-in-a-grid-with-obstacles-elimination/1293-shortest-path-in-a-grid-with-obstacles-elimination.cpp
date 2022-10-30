class Solution {
public:
        int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        int ans = path(grid, k, m-1, n-1,visited, dp);
        if(ans >= m*n)
            return -1;
        return ans;
    }

    int path(vector<vector<int>>& grid, int k, int r, int c,vector<vector<bool>>& visited, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(r >= m || c >= n || r < 0 || c < 0 || visited[r][c]){
            return 1e6;
        }

        if(dp[r][c][k] != -1){
            return dp[r][c][k];
        }
        
        if(r == 0 && c == 0){
            return dp[r][c][k] = 0;
        }

        if(grid[r][c]){
            if(k == 0){
                return dp[r][c][k] = 1e6;
            }
            else{
                k--;
            }
        }
        visited[r][c] = true;
        int top = 1+path(grid, k, r-1, c,visited, dp);
        int left = 1+path(grid, k, r, c-1,visited, dp);
        int down = 1+path(grid, k, r+1, c,visited, dp);
        int right = 1+path(grid, k, r, c+1,visited, dp);
        visited[r][c] = false;

        return dp[r][c][k] = min(top, min(left, min(right, down)));
    }
};