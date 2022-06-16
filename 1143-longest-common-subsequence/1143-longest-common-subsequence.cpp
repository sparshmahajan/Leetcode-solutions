class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector <vector<int>> dp(n+1,vector <int> (m+1,0));
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(text1[idx1-1] == text2[idx2-1])
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[n][m];
    }
};