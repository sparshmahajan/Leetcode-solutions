bool myCompare(pair<string,int> & a,pair<string,int> & b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string , int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector <string> res;
        vector<pair<string ,int>> m;
        for(auto i: mp)
            m.push_back({i.first , i.second});
        sort(m.begin(),m.end(),myCompare);
		    for(int i=0;i<k;i++){
		    res.push_back(m[i].first);
        }
        return res;
    }
};