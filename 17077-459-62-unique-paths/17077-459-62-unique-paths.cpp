class Solution {
public:
    int recursion(int curX, int curY, vector<vector<int>> &dp){
        if(curX ==0 && curY == 0)
            return 1;
        
        if(curX <0 || curY <0)
            return 0;
        
        if(dp[curX][curY] != -1){
            return dp[curX][curY];
        }

        int sumX = recursion(curX-1,curY,dp);
        int sumY = recursion(curX,curY-1,dp);
        dp[curX][curY] = sumX + sumY;
        return dp[curX][curY];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(m-1,n-1,dp);
    }
};