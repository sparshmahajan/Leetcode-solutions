class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> ans;
        int i;
        long int coeff=0;
        for(i=0;i<=rowIndex;i++){
            if(i==0 or i==rowIndex) coeff = 1;
            else coeff = coeff * (rowIndex-i+1)/i;
            ans.push_back(coeff);
        }
        return ans;
    }
};