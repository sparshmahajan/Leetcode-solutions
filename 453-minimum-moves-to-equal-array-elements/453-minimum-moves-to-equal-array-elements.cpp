class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size(),minimum = *min_element(nums.begin(),nums.end());
        return total - (n*minimum);
    }
};