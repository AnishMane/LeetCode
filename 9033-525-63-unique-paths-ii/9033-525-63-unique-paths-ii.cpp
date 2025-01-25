class Solution {
public:
    
    int recursion(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(i<0 || j<0 || j>=n) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = recursion(i,j-1,obstacleGrid,dp);
        int up = recursion(i-1,j,obstacleGrid,dp);
        
        return dp[i][j] = left + up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(m-1,n-1,obstacleGrid,dp);
    }
};