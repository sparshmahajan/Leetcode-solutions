class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set <vector<int>> ans;
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        for(int i=0;i<nums.size()-2;i++){
            int start = i+1, end = nums.size()-1,sum;
            int target = 0;
            vector <int> dp;
            while(start < end){
             sum = nums[start] + nums[end] + nums[i];
             if(sum > target) end--;
             else if(sum < target) start++;
             else{
                dp.push_back(nums[i]);
                dp.push_back(nums[start]);
                dp.push_back(nums[end]);
                ans.insert(dp);
                dp.clear();
                start++;
                end--;
             }
            }
        }
        for(auto x : ans)
            result.push_back(x);
        return result;
    }
};