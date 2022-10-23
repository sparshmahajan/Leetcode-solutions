class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        unordered_set <int> st;
        for(int i : nums)
            st.insert(i);
        int sum = accumulate(st.begin(),st.end(),0);
        
        int repeatedElement = totalSum - sum;
        int n = nums.size();
        int missingElement = (n * (n+1))/2 - sum;
        return {repeatedElement , missingElement};
    }
};