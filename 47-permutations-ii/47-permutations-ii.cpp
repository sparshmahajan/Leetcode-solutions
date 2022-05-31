class Solution {
public:
    void func(vector<int>& nums,set<vector<int>>& uniquePermutations,vector <int>& ds, vector <int> &map){
        if(ds.size() == nums.size()){
            uniquePermutations.insert(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(map[i] != 1){
                ds.push_back(nums[i]);
                map[i] = 1;
                func(nums,uniquePermutations,ds,map);
                ds.pop_back();
                map[i]=0;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set <vector<int>> uniquePermutations;
        vector<vector<int>> ans;
        vector <int> ds;
        vector <int> map(nums.size(),0);
        func(nums,uniquePermutations,ds,map);
        for(auto uniquePermutaion : uniquePermutations){
            ans.push_back(uniquePermutaion);
        }
        return ans;
    }
};