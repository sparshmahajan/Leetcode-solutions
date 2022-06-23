class Solution
{
    public:

        int numDecodings(string s)
        {
            int n = s.size();
            vector<int> dp(n+1, 0);
            dp[n] = 1;
            for (int idx = n - 1; idx >= 0; idx--)
            {
                int digit = s[idx] - '0';
                if (digit == 0)
                    dp[idx] = 0;
                else
                {
                    int ans = dp[idx + 1];

                    if (idx + 1 < s.size())
                    {
                        int digit2 = s[idx + 1] - '0';
                        int val = digit *10 + digit2;
                        if (val <= 26)
                            ans += dp[idx + 2];
                    }
                    dp[idx] = ans;
                }
            }
            return dp[0];
        }
};