class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(obstacleGrid[i][j] == 1)
            return 0;
        
        if(i == 0 && j == 0)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int move_up = 0;
        int move_left = 0;
        if(i>=1)
            move_left = solve(i-1,j,obstacleGrid,dp);
        if(j>=1)
            move_up = solve(i,j-1,obstacleGrid,dp);
        
        return dp[i][j] = move_up + move_left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() , n =  obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,obstacleGrid,dp);
    }
};