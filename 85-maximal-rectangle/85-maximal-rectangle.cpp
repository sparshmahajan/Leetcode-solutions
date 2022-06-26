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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <int> heights(n,0);
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};