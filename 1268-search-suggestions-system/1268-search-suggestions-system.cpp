class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map <string , set<string>> mp;
        for(auto p : products){
            string curr = "";
            int n = p.size();
            for(int i=0;i<n;i++){
                curr += p[i];
                mp[curr].insert(p);
            }
        }
        vector<vector<string>> ans;
        int n = searchWord.size();
        string pre = "";
        for(int i=0;i<n;i++){
            vector <string> s;
            pre += searchWord[i];
            auto it = mp[pre].begin();
            int j = 0;
            while(it != mp[pre].end() && j<3){
                s.push_back(*it);
                it++;
                j++;
            }
            ans.push_back(s);
        }
        return ans;
    }
};