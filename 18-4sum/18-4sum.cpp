class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        set <vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int start = j+1, end = nums.size()-1;
                int sum = nums[i] + nums[j];
                int required = target - sum;
                vector <int> dp;
                while(start < end){
                    sum = (nums[start] + nums[end]);
                    if(sum > required) end--;
                    else if(sum < required) start++;
                    else{
                        dp.push_back(nums[i]);
                        dp.push_back(nums[j]);
                        dp.push_back(nums[start]);
                        dp.push_back(nums[end]);
                        ans.insert(dp);
                        dp.clear();
                        start++;
                        end--;
                    }
                }
            }
        }
        for(auto x : ans)
            result.push_back(x);
        return result;
    }
};