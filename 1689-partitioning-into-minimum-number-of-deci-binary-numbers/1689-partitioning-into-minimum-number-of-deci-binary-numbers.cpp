class Solution
{
    public:
        int minPartitions(string n)
        {
            int best = 0;
            for (auto it: n)
            {
                best = max(best, it - '0');
            }
            return best;
        }
};