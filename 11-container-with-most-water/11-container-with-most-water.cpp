class Solution
{
    public:
        int maxArea(vector<int> &height)
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            
            int i = 0, j = height.size() - 1;
            int maxArea = 0;
            while (i < j)
            {
                int area = min(height[i], height[j]) * (j-i);
                maxArea = max(maxArea, area);
                if (height[i] < height[j])
                    i++;
                else
                    j--;
            }
            return maxArea;
        }
};