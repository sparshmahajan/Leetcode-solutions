class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int not_pick = 0 + prev;
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            
            int curr = max(pick,not_pick);
            prev2 = prev;
            prev = curr;
            
        }
        return prev;
    }
    

    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector <int> num1,num2;
        for(int i=0;i<n;i++){
            if(i != n-1)
                num1.push_back(nums[i]);
            if(i != 0)
                num2.push_back(nums[i]);
        }
        
        return max(solve(num1),solve(num2));
    }
};