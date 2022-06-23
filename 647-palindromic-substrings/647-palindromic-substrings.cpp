class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector <vector<int>> dp(n,vector <int> (n,0));
        int ans = 0;
        for(int diff=0;diff<n;diff++){
            for(int i=0,j=i+diff;j<n;i++,j++){
                if(i==j){
                    dp[i][j] = 1;
                    ans++;
                }
                else if(diff == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 2;
                        ans++;
                    }
                    else
                        dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};