class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++){
            if(mp[k-nums[i]] > 0){
                ans++;
                mp[k-nums[i]]--;
            }else
                mp[nums[i]]++;
        }
        return ans;
    }
};