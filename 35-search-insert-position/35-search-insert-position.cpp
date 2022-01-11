class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool present = binary_search(nums.begin(),nums.end(),target);
        vector<int>::iterator idx;
        if(present) idx = lower_bound(nums.begin(),nums.end(),target);
        else  idx = upper_bound(nums.begin(),nums.end(),target);
        return (idx-nums.begin());
        
    }
};