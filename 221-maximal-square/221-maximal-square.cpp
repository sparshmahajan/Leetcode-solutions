class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
            dp[i][0] = matrix[i][0] - '0';
        for(int i=0;i<m;i++)
            dp[0][i] = matrix[0][i]- '0';
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])) + 1;
                }
            }
        }
        
        int area = 0;
        for(auto x:dp){
            for(auto y:x)
                area = max(area,y);
        }
        return area * area;
    }
};