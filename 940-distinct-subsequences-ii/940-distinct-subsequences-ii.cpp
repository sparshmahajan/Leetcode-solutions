class Solution
{
    public:
        int mod = 1e9 + 7;
    int solve(string &s, int i,vector<unsigned long> &dp)
    {
        if (i == s.size())
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        vector<int> freq(26, 0);
        unsigned long ans = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (freq[s[j] - 'a'])
                continue;
            freq[s[j] - 'a'] = 1;
            ans = ans + 1 + solve(s, j + 1,dp) % mod;
        }
        return dp[i] = ans % mod;
    }

    int distinctSubseqII(string s)
    {
        vector<unsigned long> dp(s.size(),-1);
        return solve(s, 0,dp);
    }
};