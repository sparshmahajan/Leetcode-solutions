class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[3] == '?')
            ans *= 6;
        if(time[4] == '?')
            ans *= 10;
        if(time[0] == '?' and time[1] == '?')
            ans *= 24;
        else{
            if(time[1] == '?'){
                if(time[0] == '2')
                    ans *= 4;
                else
                    ans *= 10;
            }
            else{
                if(time[0] == '?'){
                    if(time[1] > '3')
                        ans *= 2;
                    else
                        ans *= 3;
                }
            }
        }
        return ans;
    }
};