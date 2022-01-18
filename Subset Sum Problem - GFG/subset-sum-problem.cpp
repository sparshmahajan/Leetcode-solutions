// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool subsetSum(int a[],int n, int sum,vector <vector<int>>& tab){
        // code here 
        if (sum == 0)
        return 1;
        
    if (n <= 0)
        return 0;
  
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum,tab);
    else
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum,tab) || subsetSum(a, n - 1, sum - a[n - 1],tab);
    }
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<vector<int>> dp(N+1,vector <int>(sum+1,-1));
        return subsetSum(arr,N,sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends