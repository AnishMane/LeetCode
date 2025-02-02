class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0] = 1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                long nottake = dp[i-1][j];
                long take = 0;
                if(t[j-1]==s[i-1]) take = dp[i-1][j-1];

                dp[i][j] = take + nottake;
            }
        }
        
        return dp[m][n];
    }
};