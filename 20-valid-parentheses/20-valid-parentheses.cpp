class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()) return false;
                char temp = stk.top();
                stk.pop();
                if(temp == '('){
                    if(s[i]!=')') return false;
                }
                if(temp == '{'){
                    if(s[i]!='}') return false;
                }if(temp == '['){
                    if(s[i]!=']') return false;
                }
            }
        }
        return stk.empty();
    }
};