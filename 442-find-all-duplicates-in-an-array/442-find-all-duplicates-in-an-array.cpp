class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        for(int x : nums){
            int y = abs(x);
            if(nums[y-1] < 0)
                ans.push_back(y);
            nums[y-1] *= -1;
        }
        return ans;
    }
};