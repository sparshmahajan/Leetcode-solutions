class Solution {
public:
    void func(int idx,vector<int>& nums,set<vector<int>>& uniquePermutations){
        if(idx == nums.size()){
            uniquePermutations.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            func(idx+1,nums,uniquePermutations);
            swap(nums[idx],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set <vector<int>> uniquePermutations;
        vector<vector<int>> ans;
        func(0,nums,uniquePermutations);
        for(auto uniquePermutaion : uniquePermutations){
            ans.push_back(uniquePermutaion);
        }
        return ans;
    }
};