class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        int i,j,n=nums.size();
        for(i=0;i<n;i++){
            int a = target - nums[i];
            for(j=i+1;j<n;j++){
                if(a == nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};