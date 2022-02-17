class Solution {
public:
    
    void helper(vector<int>& candidates, int target,vector<vector<int>>& ans,vector <int>& r,int i){
        if(target == 0){
            ans.push_back(r);
            return;
        }
        
        while(i < candidates.size() and target-candidates[i]>=0){
            r.push_back(candidates[i]);
            helper(candidates,target-candidates[i],ans,r,i);
            i++;
            
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans; 
        vector <int> r;
        helper(candidates,target,ans,r,0);
        return ans;
    }
};