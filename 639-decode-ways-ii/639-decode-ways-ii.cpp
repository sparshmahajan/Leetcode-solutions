class Solution
{
    public:
        int mod = 1e9 + 7;
    int solve(int i, string &s, vector<long> &dp)
    {
        if (i >= s.size())
            return 1;

        int digit = s[i] - '0';
        if (digit == 0)
            return dp[i] = 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = 0;

        if (i + 1 < s.size() and s[i] == '*'
            and s[i + 1] == '*')
            ans += ((long)15* solve(i + 2, s, dp) % mod) % mod;
        else if (i + 1 < s.size() and s[i] == '*'
            and s[i + 1] != '*')
        {
            int digit2 = s[i + 1] - '0';
            if (digit2 >= 0 and digit2 <= 6)
                ans += ((long)2* solve(i + 2, s, dp) % mod) % mod;
            else
                ans += solve(i + 2, s, dp) % mod;
        }
        else if (i + 1 < s.size() and s[i] != '*'
            and s[i + 1] == '*')
        {
            if (digit == 1)
                ans += ((long) 9* solve(i + 2, s, dp) % mod) % mod;
            else if (digit == 2)
                ans += ((long) 6* solve(i + 2, s, dp) % mod) % mod;
        }
        else if (i + 1 < s.size())
        {
            int digit2 = s[i + 1] - '0';
            int val = digit *10 + digit2;
            if (val <= 26)
                ans += solve(i + 2, s, dp) % mod;
        }

        if (s[i] == '*')
           ans += ((long) 9* solve(i + 1, s, dp) % mod) % mod;
        else
            ans += solve(i + 1, s, dp) % mod;
        ans = ans%mod;
        return dp[i] = ans;
    }

    int numDecodings(string s)
    {
        vector<long> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};