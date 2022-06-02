class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector <vector<int>> result(matrix[0].size(),vector <int> (matrix.size()));
        int i,j;
        for(i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                result[n-1-j][n-1-i] = matrix[i][j];
            }
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                matrix[i][j] = result[i][j];
            }
        }
    }
};