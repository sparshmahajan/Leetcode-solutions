class Solution {
public:
    void func(vector<int>& nums,vector<vector<int>>& ans,vector <int>& ds, vector <int> &map){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
        }
        for(int i=0;i<nums.size();i++){
            if(map[i] != 1){
                ds.push_back(nums[i]);
                map[i] = 1;
                func(nums,ans,ds,map);
                ds.pop_back();
                map[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> ans;
        vector <int> ds;
        vector <int> map(nums.size(),0);
        func(nums,ans,ds,map);
        return ans;
    }
};