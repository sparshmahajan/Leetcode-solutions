class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            unordered_map <int,int> mp;
            for(int j=0;j<n;j++){
                mp[matrix[i][j]]++;
             }
            if(mp.size() != n)
                return false;
        }
        for(int i=0;i<n;i++){
            unordered_map <int,int> mp;
            for(int j=0;j<n;j++){
                mp[matrix[j][i]]++;
             }
            if(mp.size() != n)
                return false;
        }
        return true;
    }
};