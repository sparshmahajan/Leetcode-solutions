class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int sum = 0, res = 0,count=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            res = sum % k;
            if(res < 0)
                res += k;
            if(mp.find(res) != mp.end())
                count += mp[res];
            mp[res]++;
        }
        return count;
    }
};