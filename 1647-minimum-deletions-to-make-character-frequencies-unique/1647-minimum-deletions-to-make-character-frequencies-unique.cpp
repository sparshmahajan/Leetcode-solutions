class Solution
{
    public:
        int minDeletions(string s)
        {
            int n = s.size();
            vector<int> freq(26, 0);
            for (int i = 0; i < n; i++)
            {
                freq[s[i] - 'a']++;
            }
            sort(freq.begin(), freq.end());
            int del = 0;
            for (int i = 24; i >= 0; i--)
            {
                if (freq[i] == 0)
                    break;

                if (freq[i] >= freq[i + 1])
                {
                    int prev = freq[i];
                    freq[i] = max(0, freq[i + 1] - 1);
                    del += prev - freq[i];
                }
            }
            return del;
        }
};