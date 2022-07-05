class Solution
{
    public:
        int maxConsecutive(int bottom, int top, vector<int> &special)
        {
            sort(special.begin(), special.end());
            int len = 0;
            int ans = 0;
            for(int i=1;i<special.size();i++){
                ans = max(ans,special[i]-special[i-1]-1);
            }
            return max(ans,max(special[0]-bottom,top-special[special.size()-1]));
        }
};