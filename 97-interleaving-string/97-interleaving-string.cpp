class Solution
{
    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            if (s1.size() + s2.size() != s3.size())
                return false;
            vector<int> prev(s2.size() + 1, 0),curr(s2.size()+1,0);
            for (int i = 0; i <= s1.size(); i++)
            {
                for (int j = 0; j <= s2.size(); j++)
                {
                    if (i == 0 and j == 0)
                    {
                        curr[j] = 1;
                        prev[j] = 1;
                        continue;
                    }
                    if (i > 0 and s1[i - 1] == s3[i + j - 1] and j > 0 and s2[j - 1] == s3[i + j - 1])
                        curr[j] = prev[j] or curr[j - 1];
                    else if (i > 0 && s1[i - 1] == s3[i + j - 1])
                        curr[j] = prev[j];
                    else if (j > 0 && s2[j - 1] == s3[i + j - 1])
                        curr[j] = curr[j - 1];
                    else
                        curr[j] = false;
                }
                prev = curr;
            }
            return prev[s2.size()];
        }
};