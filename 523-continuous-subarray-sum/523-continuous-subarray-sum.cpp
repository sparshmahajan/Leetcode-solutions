class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end()){
                if(i - mp[rem] > 1)
                    return true;
            }
            else
                mp[rem] = i;
            if(rem == 0 && i>0)
                return true;
        }
        return false;
    }
};