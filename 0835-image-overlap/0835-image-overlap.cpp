class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector <pair<int,int>> non_zero1 , non_zero2;
        int n = img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j] == 1)
                    non_zero1.push_back({i,j});
                if(img2[i][j] == 1)
                    non_zero2.push_back({i,j});
            }
        }
        
        int ans = 0;
        map <pair<int,int> , int> mp;
        for(auto i: non_zero1){
            for(auto j: non_zero2){
                int x = i.first - j.first;
                int y = i.second - j.second;
                mp[{x,y}]++;
                ans = max(ans,mp[{x,y}]);
            }
        }
        return ans;
    }
};