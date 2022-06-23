class Solution {
public:
    int solve(int idx ,string& s,vector <int>& dp){
        if(idx >= s.size())
            return 1;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int digit = s[idx] - '0';
        if(digit == 0)
            return 0;
        
        int ans = solve(idx+1,s,dp);
        
        if(idx+1 < s.size()){
            int digit2 = s[idx+1] - '0';
            int val = digit * 10 + digit2;
            if(val <= 26)
                ans += solve(idx+2,s,dp);
        }
        return dp[idx] = ans;
        
    }
    int numDecodings(string s) {
        vector <int> dp(s.size(),-1);
        return solve(0,s,dp);
    }
};