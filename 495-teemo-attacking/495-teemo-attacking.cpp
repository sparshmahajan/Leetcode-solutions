class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0,i;
        for(i=1;i<timeSeries.size();i++){
            if(timeSeries[i-1] + duration <= timeSeries[i]) 
                sum += duration;
            else 
                sum += (timeSeries[i]-timeSeries[i-1]);
        }
        sum += duration;
        return sum;
    }
};