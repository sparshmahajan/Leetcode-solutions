class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    int len=i-st.top();
                    maxi=max(maxi,len);
                }
            }
        }
        return maxi;

    }
};