class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector <bool> v(nums.size(),false);
        int element;
        for(int i : nums)
           v[i]=true;
        for(int i =0;i<v.size();i++){
            if(v[i] != true){
                element = i;
                break;
            }
        }
        return element;
    }
};