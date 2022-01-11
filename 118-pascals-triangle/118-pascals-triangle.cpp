class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int i,j,coeff=0;
        vector <int> a;
        for(i=0;i<numRows;i++){
            a.clear();
            for(j=0;j<=i;j++){
                if(i==0 or j==0){
                    coeff = 1;
                    cout<<coeff<<" ";
                    a.push_back(coeff);
                }
                else{
                    coeff = coeff * (i-j+1)/j;
                    cout<<coeff<<" ";
                    a.push_back(coeff);
                }
            }
            cout<<endl;
            ans.push_back(a);
        }
        return ans;
    }
};