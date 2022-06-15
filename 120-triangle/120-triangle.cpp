class Solution {
public:
//     int solve(int i,int j,vector <vector<int>>& triangle,vector <vector<int>>& dp){
//         if(i == triangle.size()-1){
//             return dp[i][j] = triangle[i][j];
//         }
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int down = solve(i+1,j,triangle,dp);
//         int down_right = solve(i+1,j+1,triangle,dp);
        
//         return dp[i][j] = triangle[i][j] + min(down,down_right);
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() ;
        int m = triangle[n-1].size();
        vector <vector<int>> dp(n+1,vector <int> (m+1,-1));
        for(int j=0;j<m;j++)
            dp[n-1][j] = triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up = dp[i+1][j] + triangle[i][j];
                int up_left = dp[i+1][j+1] + triangle[i][j];
                
                dp[i][j] = min(up,up_left);
            }
        }
        return dp[0][0];
    }
};