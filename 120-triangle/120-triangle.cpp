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
        vector <int> last (m,-1),curr(m,-1);
        for(int j=0;j<m;j++)
            last[j] = triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = last[j] + triangle[i][j];
                int down_right = last[j+1] + triangle[i][j];
                
                curr[j] = min(down,down_right);
            }
            last = curr;
        }
        return last[0];
    }
};