class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if(nums.size() == 0)
                return 0;
            unordered_map<int, int> mp;
            for (int x: nums)
                mp[x] = 1;

            for (int x: nums)
            {
                if (mp.find(x-1) != mp.end())
                    mp[x] = 0;
            }

            int ans = 1;
            for (int x: nums)
                {
                    if (mp[x] == 1)
                    {
                        int length = 1;
                        while (mp.find(x + length) != mp.end()){
                            length++;
                        }
                        ans = max(length, ans);
                    }
                }
                return ans;
            }
        };