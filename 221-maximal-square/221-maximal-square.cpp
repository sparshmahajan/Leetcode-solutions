class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int> prev(m,0),curr(m,0);
        
        int area = 0;
        for(int i=0;i<m;i++){
            prev[i] = matrix[0][i]- '0';
            area = max(prev[i],area);
        }

        for(int i=1;i<n;i++){
            curr[0] = matrix[i][0] - '0';
            area = max(curr[0],area);
            for(int j=1;j<m;j++){
                if(matrix[i][j] == '1'){
                    curr[j] = min(curr[j-1],min(prev[j],prev[j-1])) + 1;
                    area = max(area,curr[j]);
                }
                else{
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        
        return area * area;
    }
};