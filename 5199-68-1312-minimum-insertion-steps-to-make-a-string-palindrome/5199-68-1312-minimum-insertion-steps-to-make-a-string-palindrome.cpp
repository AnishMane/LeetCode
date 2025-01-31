class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    int first = dp[i-1][j];
                    int second = dp[i][j-1];

                    dp[i][j] = max(first,second);
                }
                
                
            }
        }

        int lps = dp[n][n];

        return n-lps;
    }
};