class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> stk;
        int maxArea = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            while(!stk.empty() and (i==n or heights[stk.top()] >= heights[i])){
                int height = heights[stk.top()];
                stk.pop();
                int width;
                if(stk.empty())
                    width = i;
                else
                    width = i- stk.top()- 1;
                maxArea = max(maxArea,width * height);
            }
            stk.push(i);
        }
        return maxArea;
    }
};