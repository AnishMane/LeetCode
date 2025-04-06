class Solution {
public:

    bool recursion(int i, int j, string s, string p, vector<vector<int>>&dp){
        int m = s.size();
        int n = p.size();
        if(j==n) return i==m;
        if(dp[i][j]!=-1) return dp[i][j];

        bool check = (i<m && (s[i]==p[j] || p[j]=='.'));

        if(j+1<n && p[j+1] == '*'){
            return dp[i][j] = recursion(i,j+2,s,p,dp) || (check && recursion(i+1,j,s,p,dp));
        }

        if(check) return dp[i][j] = recursion(i+1,j+1,s,p,dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recursion(0,0,s,p,dp);
    }
};