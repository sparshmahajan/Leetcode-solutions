class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),maxJump = 0,i;
        for(i=0;i<n;i++){
            maxJump = max(maxJump,i+nums[i]);
            if(maxJump>=(n-1)) 
                return true;
            if(maxJump <= i) 
                return false;
        }
        return false;
    }
};