class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-3;
        while(n >= 0){
            if(nums[n] + nums[n+1] > nums[n+2]){
                return nums[n] + nums[n+1] + nums[n+2];
            }
            n--;
        }
        return 0;
    }
};