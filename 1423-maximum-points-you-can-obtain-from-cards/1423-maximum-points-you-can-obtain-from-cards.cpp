class Solution
{
    public:
        int maxScore(vector<int> &cardPoints, int k)
        {
            int n = cardPoints.size();
            int sum = 0;
            for (int x: cardPoints)
                sum += x;

            if (n == k)
                return sum;

            int window = 0;
            for (int i = 0; i < n - k - 1; i++)
                window += cardPoints[i];

            int ans = 0;
            for (int i = n - k - 1; i < n; i++)
            {
                window += cardPoints[i];
                ans = max(ans, sum - window);
                window -= cardPoints[i - (n - k - 1)];
            }
            return ans;
        }
};