class Solution {
public:
    void solve(int i,int k,int& n,int sum ,vector<int> ds, vector<vector<int>>& ans){
        if(k == 0){
            if(sum == n){
                ans.push_back(ds);
            }
            return ;
        }
        
        if(sum > n)
            return;
        
        for(int idx=i;idx<10;idx++){
            ds.push_back(idx);
            solve(idx+1,k-1,n,sum+idx,ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,0,ds,ans);
        return ans;
    }
};