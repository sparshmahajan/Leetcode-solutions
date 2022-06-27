class Solution {
public:
    int minPartitions(string n) {
        int best = 0;
        for(auto it : n){
            int num = it - '0';
            best = max(best,num);
        }
        return best;
    }
};