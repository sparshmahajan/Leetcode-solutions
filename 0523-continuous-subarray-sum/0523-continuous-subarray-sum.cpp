class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res;
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            res = sum % k;
            if(mp.find(res) != mp.end()){
                if(i - mp[res] > 1)
                    return true;
            }
            else
                mp[res] = i;
            if(res == 0 and i > 0)
                return true;
        }
        return false;
    }
};