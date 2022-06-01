class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector <vector<int>> ans;
        int n = intervals.size(),i;
        vector <int> interval;
        sort(intervals.begin(),intervals.end());
        // for(auto x : intervals){
        //     for(auto y : x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        for(i=0; i<n; i++){
            interval.push_back(intervals[i][0]);
            int j = intervals[i][1];
            while(i < n-1 && j >= intervals[i+1][0]){
                if(intervals[i+1][1] > j)
                    j = intervals[i+1][1];
                i++;
            }
            if(intervals[i][1] > j)
                    j = intervals[i][1];
            interval.push_back(j);
            ans.push_back(interval);
            interval.clear();
        }
        return ans;
    }
};