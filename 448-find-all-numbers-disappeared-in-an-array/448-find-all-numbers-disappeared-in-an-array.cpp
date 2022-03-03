class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> n(nums.size()+1,0);
        vector <int> ans;
        for(auto x : nums)
            n[x]++;
        for(int i=1;i<=nums.size();i++){
            if(n[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};