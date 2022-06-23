class Solution
{
    public:
        int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int l = horizontalCuts[0], r = verticalCuts[0];

        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        for (int i = horizontalCuts.size() - 2; i >= 0; i--)
        {
            l = max(l, horizontalCuts[i + 1] - horizontalCuts[i]);
        }

        for (int i = verticalCuts.size() - 2; i >= 0; i--)
        {
            r = max(r, verticalCuts[i + 1] - verticalCuts[i]);
        }

        return ((long long)(l % MOD) *(r % MOD)) % MOD;
    }
};