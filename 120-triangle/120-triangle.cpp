class Solution {
public:
    int solve(int i,int j,vector <vector<int>>& triangle,vector <vector<int>>& dp){
        if(i == triangle.size()-1){
            return dp[i][j] = triangle[i][j];
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = solve(i+1,j,triangle,dp);
        int down_right = solve(i+1,j+1,triangle,dp);
        
        return dp[i][j] = triangle[i][j] + min(down,down_right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        int m = triangle[n-1].size();
        vector <vector<int>> dp(n,vector <int> (m,-1));
        return solve(0,0,triangle,dp);
    }
};