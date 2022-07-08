class Solution
{
    public:
        int mod = 1e9 + 7;
    int distinctSubseqII(string s)
    {
        vector < unsigned long > dp(s.size() + 1, 0);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            vector<int> freq(26, 0);
            unsigned long ans = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (freq[s[j] - 'a'])
                    continue;
                freq[s[j] - 'a'] = 1;
                ans = ans + 1 + dp[j + 1] % mod;
            }
            dp[i] = ans % mod;
        }
        return dp[0];
    }
};