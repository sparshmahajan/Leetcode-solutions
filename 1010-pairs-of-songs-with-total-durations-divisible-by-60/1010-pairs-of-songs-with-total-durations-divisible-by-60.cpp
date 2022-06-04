class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map <int,int> mp;
        for(int i=0;i<time.size();i++){
            time[i] = time[i] % 60;
        }
        int count=0;
        for(int x : time){
            if(x == 0) count += mp[0] ;
            if(mp.find(60-x) != mp.end())
                count += mp[60-x];
            mp[x]++;
        }
        return count;
    }
};