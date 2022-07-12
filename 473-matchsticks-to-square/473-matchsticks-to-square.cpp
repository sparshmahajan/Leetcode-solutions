class Solution
{
    public:
        bool solve(int i, vector<int> &matchsticks, int a, int b, int c, int d)
        {
            if (i == matchsticks.size())
            {
                if(a == 0 and b == 0 and c == 0 and d == 0)
                    return true;
                return false;
            }
            
            if (a >= matchsticks[i])
            {
                if (solve(i + 1, matchsticks, a - matchsticks[i], b, c, d))
                    return true;
            }

            if (b >= matchsticks[i])
            {
                if (solve(i + 1, matchsticks, a, b - matchsticks[i], c, d))
                    return true;
            }

            if (c >= matchsticks[i])
            {
                if (solve(i + 1, matchsticks, a, b, c - matchsticks[i], d))
                    return true;
            }

            if (d >= matchsticks[i])
            {
                if (solve(i + 1, matchsticks, a, b, c, d - matchsticks[i]))
                    return true;
            }

            return false;
        }

    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() < 4)
        {
            return false;
        }

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;

        int a, b, c, d;
        a = b = c = d = (sum / 4);

        sort(matchsticks.rbegin(), matchsticks.rend());

        return solve(0, matchsticks, a, b, c, d);
    }
};