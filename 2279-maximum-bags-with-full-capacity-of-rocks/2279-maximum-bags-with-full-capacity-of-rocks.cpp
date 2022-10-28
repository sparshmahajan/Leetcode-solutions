class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            rocks[i] = capacity[i] - rocks[i];
        }
        sort(rocks.begin(),rocks.end());
        for(int i=0;i<n;i++){
            if(additionalRocks == 0)
                break;
            if(rocks[i] != 0){
                if(additionalRocks - rocks[i] >= 0){
                    additionalRocks = additionalRocks - rocks[i];
                    rocks[i] = 0;
                }
            }
        }
        
        for(int i : rocks){
            if(i == 0)
                ans++;
        }
        return ans;
    }
};