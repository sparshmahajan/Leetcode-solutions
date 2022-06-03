class Solution {
public:
    void solve(int left,int right,string parenthesis,vector<string>& ans){
        if(left == 0 && right == 0){
            cout<<parenthesis<<endl;
            ans.push_back(parenthesis);
            return;
        }
        if(left > 0){
            solve(left-1,right,parenthesis + "(",ans);
        }
        if(right > left){
            solve(left,right-1,parenthesis + ")",ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string parenthesis;
        solve(n,n,"",ans);
        return ans;
    }
};