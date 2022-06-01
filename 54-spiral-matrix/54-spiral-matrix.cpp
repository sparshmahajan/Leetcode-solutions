class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startCol = 0, endCol = matrix[0].size()-1, startRow = 0, endRow = matrix.size()-1;
        vector <int> ans;
        int count = 0 , total = matrix.size() * matrix[0].size();
        while(count < total){
            for(int i=startCol ;count < total && i <= endCol;i++){
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow ;count < total && i <= endRow;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol ;count < total && i >= startCol;i--){
                    ans.push_back(matrix[endRow][i]);
                    count++;
            }
            endRow--;
            for(int i=endRow ;count< total && i >= startRow;i--){
                    ans.push_back(matrix[i][startCol]);
                    count++;
            }
            startCol++;
        }
        return ans;
    }
};