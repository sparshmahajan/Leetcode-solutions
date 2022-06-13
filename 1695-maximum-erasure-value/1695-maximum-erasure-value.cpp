class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0;
        unordered_set <int> mp;
        int curr = 0 , ans = 0;
        for(int i=0;i<nums.size();i++){
            while(mp.count(nums[i]) >0){
                curr -= nums[start];
                mp.erase(nums[start]);
                start++;
            }
            mp.insert(nums[i]);
            curr += nums[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};