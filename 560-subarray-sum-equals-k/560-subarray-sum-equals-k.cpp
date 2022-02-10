class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),i;
        unordered_map <int,int> mp;
        vector <int> prefix(n);
        prefix[0] = nums[0];
        for(i=1;i<n;i++){
            prefix[i] = nums[i] + prefix[i-1];            
        }
        int ans=0;
        for(i=0;i<n;i++){
            if(prefix[i] == k)
                ans++;
            if(mp.find(prefix[i]-k) != mp.end()){
                ans += mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};