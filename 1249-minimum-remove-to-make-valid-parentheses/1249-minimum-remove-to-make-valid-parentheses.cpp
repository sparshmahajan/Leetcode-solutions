class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string x = "";
        vector <int> idx;
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(idx.empty() and s[i]==')'){
                count++;
                continue;
            }
            else if(s[i]=='('){
                idx.push_back(i-count);
            }
            else if(s[i]==')') idx.pop_back();
            x += s[i];
        }
        while(!idx.empty()){
            x.erase(idx.back(),1);
            idx.pop_back();
        }
        return x;
    }
};