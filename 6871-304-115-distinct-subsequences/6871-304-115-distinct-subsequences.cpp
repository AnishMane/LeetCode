class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        vector<int> prev(n+1,0), cur(n+1,0);
        prev[0] = cur[0] = 1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                long nottake = prev[j];
                long take = 0;
                if(t[j-1]==s[i-1]) take = prev[j-1];

                cur[j] = take + nottake;
            }
            prev = cur;
        }
        
        return prev[n];
    }
};