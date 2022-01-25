class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return 0;
        int res=0,i;
        for(i=0;i<arr.size()-1;i++){
            if(arr[i]>=arr[i+1]) break;
        }
        if(i==0) return 0;
        for(i;i<arr.size()-1;i++){
            if(arr[i]<=arr[i+1]) {
                return res=0;
            }
            else res = 1;
        }
        return res;
    }
};