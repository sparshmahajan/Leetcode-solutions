class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> vec(n,vector<int> (m,0));
        if(word1[0]==word2[0])vec[0][0]= 1;
        for(int i =1;i<n;i++){
		     vec[i][0]=vec[i-1][0]; 
           if(word1[i]==word2[0])vec[i][0]=1;   
        }
        for(int i =1;i<m;i++){
		 vec[0][i]=vec[0][i-1]; 
           if(word1[0]==word2[i])vec[0][i]=1;
        }
        for(int i =1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(word1[i]==word2[j])vec[i][j] = max({1+vec[i-1][j-1],vec[i-1][j],vec[i][j-1]});
                else{
                    vec[i][j] = max(vec[i-1][j],vec[i][j-1]);
                }
        } }
                // we got the length of LCS in vec[n-1][m-1]
        return n+m-(2*vec[n-1][m-1]);       //  delete operations will be n-lcs + m-lcs 
    }
};