class Solution
{
    public:
        int numDistinct(string s, string t)
        {
            int m = s.size(), n = t.size();
            vector<unsigned long> prev(n + 1, 0),curr(n+1,0);
            prev[0] = 1;

            for (int i = 1; i <= m; i++)
            {
                curr[0] = 1;
                for (int j = 1; j <= n; j++)
                {
                    unsigned long pick = 0, not_pick = 0;
                    
                    if (s[i - 1] == t[j - 1])
                        pick = prev[j - 1];
                    not_pick = prev[j];

                    curr[j] = pick + not_pick; 
                }
                prev = curr;
            }
            return prev[n];
        }
};