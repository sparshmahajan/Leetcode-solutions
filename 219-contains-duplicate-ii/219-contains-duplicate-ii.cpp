class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector <pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = make_pair(nums[i],i);
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            int diff = abs(arr[i].second - arr[i-1].second);
            if(arr[i-1].first == arr[i].first && diff <= k )
                return true;
        }
        return false;
    }
};