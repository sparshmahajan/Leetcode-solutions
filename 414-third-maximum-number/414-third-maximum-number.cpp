class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set <int> s;
        for(int i : nums){
            s.insert(i);
        }
       // for(auto i : s) cout<<i<<" ";
        if(s.size()<3) return *(--s.end());
        return *(------s.end());
        
    }
};