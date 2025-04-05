class Solution {
public:

    int recursion(int i, int j, string word1, string word2, vector<vector<int>>&dp){
        if(j==0) return i;
        if(i==0) return j;
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i-1] == word2[j-1]) return 0 + recursion(i-1,j-1,word1,word2,dp);
        int insert = 1 + recursion(i,j-1,word1,word2,dp);
        int del = 1 + recursion(i-1,j,word1,word2,dp);
        int replace = 1 + recursion(i-1,j-1,word1,word2,dp);

        return dp[i][j] = min(insert,min(del,replace));
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recursion(m,n,word1,word2,dp);
    }
};