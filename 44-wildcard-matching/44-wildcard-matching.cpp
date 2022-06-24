class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<int>> dp(n+1,vector <int>(m+1,0));
        dp[0][0] = 1;
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int jj=1;jj<=j;jj++){
                if(p[jj-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s[i-1] == p[j-1] or p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
        
                else if(p[j-1] == '*')
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};