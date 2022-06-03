class NumMatrix {
public:
    vector <vector<int>> mat;
    
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector <int> row(matrix[0].size(),0);
            row[0]=matrix[i][0];
            for(int j=1;j<matrix[0].size();j++)
                row[j] = row[j-1] + matrix[i][j];
            mat.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0, minus = 0;
        for(int i=row1;i<=row2;i++){
            sum += mat[i][col2];
            if(col1 > 0)
                minus += mat[i][col1-1];
        }
        return sum-minus;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */