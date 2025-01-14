class Solution {
public:

    int recursion(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i==0 && j==0) return grid[0][0];

        int up = grid[i][j] + recursion(i-1,j,grid,dp);
        int left = grid[i][j] + recursion(i,j-1,grid,dp);

        dp[i][j] = min(up,left);
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(m-1, n-1,grid,dp);
    }
};