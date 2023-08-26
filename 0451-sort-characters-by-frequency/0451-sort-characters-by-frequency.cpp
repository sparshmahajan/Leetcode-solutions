class Solution {
public:
        string frequencySort(string s) {
        map<char, int> Counter;
        for(int i = 0; i < s.size(); ++i) Counter[s[i]]++;
        priority_queue<pair<int, char>> pq;
        for(auto [x,y] : Counter){
            pq.push({y,x});
        }
        string res = "";
        while (!pq.empty()) {
            auto [occ, ch] = pq.top();
            pq.pop();
            res.append(occ, ch);
        }
        return res;
    }

};