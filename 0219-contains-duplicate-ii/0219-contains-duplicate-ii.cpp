class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int diff;
        for(int i=1;i<n;i++){
            diff = abs(v[i].second - v[i-1].second);
            if(v[i].first == v[i-1].first and diff <= k)
                return true;
        }
        return false;
    }
};