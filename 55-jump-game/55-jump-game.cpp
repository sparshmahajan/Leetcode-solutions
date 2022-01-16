class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;
        for(int i=0;i<n;i++){
            maxJump = max(maxJump,i+nums[i]);
            if(maxJump>=(n-1)) return true;
            if(maxJump <= i) return false;
        }
        return false;
    }
};