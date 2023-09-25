//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    void solve(int i,int j,vector<vector<int>> &m, int n,string s,vector<vector<int>> &visited,vector<string> &ans){
        if(i >= n or j >= n or i < 0 or j < 0 or !m[i][j] or visited[i][j]) {
            return;
        }
        
        if(i == n-1 and j == n-1){
            ans.push_back(s);
            return;
        }
        
        visited[i][j] = 1;
        solve(i+1,j,m,n,s+"D",visited,ans);
        solve(i,j-1,m,n,s+"L",visited,ans);
        solve(i,j+1,m,n,s+"R",visited,ans);
        solve(i-1,j,m,n,s+"U",visited,ans);
        visited[i][j] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> ans;
        solve(0,0,m,n,"",visited,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends