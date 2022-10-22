class Solution {
public:
        string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(char c : t) m[c]++;

        int i = 0, d = INT_MAX, cnt = m.size();
        string ans;
        for(int j=0; j<s.size(); j++) {
            m[s[j]]--;
            if(!m[s[j]]) 
                cnt--;
            while(!cnt) {
                if(j - i + 1 < d) 
                    d = j - i + 1, ans = s.substr(i, j - i + 1);
                m[s[i]]++;
                if(m[s[i]] > 0) 
                    cnt++;
                i++;
            }
        }
        return ans;
    }

};