class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if (nums.size() == 0)
                return 0;
            unordered_set<int> mp(nums.begin(), nums.end());

            int ans = 1;
            for (int x: nums)
            {
                if (mp.find(x - 1) != mp.end())
                    continue;
                else
                {
                    int length = 1;
                    while (mp.find(x + length) != mp.end())
                    {
                        length++;
                    }
                    ans = max(length, ans);
                }
            }
            return ans;
        }
};