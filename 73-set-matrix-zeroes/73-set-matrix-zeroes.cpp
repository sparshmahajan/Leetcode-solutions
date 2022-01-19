class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i,j;
        bool a = 0, b = 0;
        for(i=0;i<row;i++) if(matrix[i][0]==0) a = true;
        for(i=0;i<col;i++) if(matrix[0][i]==0) b = true;
        
        for(i=1;i<row;i++){
            for(j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(j=1;j<col;j++)
                    matrix[i][j]=0;
            }
        }
        for(i=1;i<col;i++){
            if(matrix[0][i]==0){
                for(j=1;j<row;j++)
                    matrix[j][i]=0;
            }
        }
        if(a){
            for(i=0;i<row;i++){
                matrix[i][0] = 0;
            }
        }
        if(b){
            for(i=0;i<col;i++){
                matrix[0][i] = 0;
            }
        }
    }
};