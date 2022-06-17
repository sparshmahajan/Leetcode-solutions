class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        int prev2 = cost[0];
        int prev = cost[1];
        int curr;
        for(int i=2;i<=n;i++){
            curr = cost[i]+min(prev,prev2);
            prev2 = prev;
            prev = curr;
        }
        
        return min(prev2,prev);
    }
    
};