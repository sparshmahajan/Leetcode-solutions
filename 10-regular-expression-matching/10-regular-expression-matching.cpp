class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            int n = s.size(), m = p.size();
            vector<bool> prev(m + 1, false) , curr(m+1,false);
            prev[0] = true;
            for (int j = 2; j <= m; j++)
            {
                if (p[j - 1] == '*')
                    prev[j] = prev[j - 2];
                else
                    prev[j] = false;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i - 1] == p[j - 1] or p[j - 1] == '.')
                        curr[j] = prev[j - 1];

                    else if (p[j - 1] == '*')
                    {
                        if (p[j - 2] == s[i - 1] or p[j - 2] == '.')
                        {
                            curr[j] = prev[j] or curr[j - 2];
                        }
                        else
                        {
                            curr[j] = curr[j - 2];
                        }
                    }
                    else
                        curr[j] = false;
                }
                prev = curr;
            }
            return prev[m];
        }
};