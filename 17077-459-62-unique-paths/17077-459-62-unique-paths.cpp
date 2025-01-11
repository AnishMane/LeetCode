class Solution {
public:
    int recursion(int curX, int curY,int m, int n, int total, vector<vector<int>> &dp){
        if(curX>=m || curY >=n)
            return 0;
        if(dp[curX][curY] != -1){
            return dp[curX][curY];
        }
        if(curX == m-1 && curY == n-1){
            return total+1;
        }

        int sumX = recursion(curX+1,curY,m,n,total,dp);
        int sumY = recursion(curX,curY+1,m,n,total,dp);
        dp[curX][curY] = sumX + sumY;
        return dp[curX][curY];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(0,0,m,n,0,dp);
    }
};