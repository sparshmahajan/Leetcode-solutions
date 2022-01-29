class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),i;
        vector <int> left(n),right(n);
        stack <int> stk;
        
        for(i=0;i<n;i++){
            if(stk.empty()){
                left[i]=0;
                stk.push(i);
            }
            else{
                while(!stk.empty() and heights[stk.top()] >= heights[i])
                    stk.pop();
                left[i] = stk.empty() ? 0 : stk.top()+1; 
                stk.push(i);
            }
        }
        
        while(!stk.empty())
            stk.pop();
         for(i=n-1;i>=0;i--){
            if(stk.empty()){
                right[i]=n-1;
                stk.push(i);
            }
            else{
                while(!stk.empty() and heights[stk.top()] >= heights[i])
                    stk.pop();
                right[i] = stk.empty() ? n-1 : stk.top()-1; 
                stk.push(i);
            }
        }
        int max_area = 0;
        for(i=0;i<n;i++){
            int area = heights[i] * (right[i] - left[i] + 1);
            max_area = max(max_area,area);
        }
        return max_area;
    }
};