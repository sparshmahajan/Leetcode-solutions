class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int temp = values[0];
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans,values[i]-i+temp);
            temp = max(temp,values[i]+i);
        }
        return ans;
    }
};