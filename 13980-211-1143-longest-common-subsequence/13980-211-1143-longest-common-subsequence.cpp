class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int ind1=0;ind1<=m;ind1++) dp[ind1][0];
        for(int ind2=0;ind2<=n;ind2++) dp[0][ind2];

        
        for(int ind1=1;ind1<=m;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    int first = dp[ind1-1][ind2];
                    int second = dp[ind1][ind2-1];

                    dp[ind1][ind2] = max(first,second);
                }
                
            }
        }
        
        return dp[m][n];
    }
};