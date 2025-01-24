class Solution {
public:
    
    int recursion(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        int r = grid.size();
        int c = grid[0].size();
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = INT_MIN;
        for(int dj1=-1;dj1<=1;++dj1){
            for(int dj2=-1;dj2<=1;++dj2){
                if(j1==j2) maxi = max(maxi, grid[i][j1] + recursion(i+1,j1+dj1,j2+dj2,grid,dp));
                else maxi = max(maxi,grid[i][j1] + grid[i][j2] + recursion(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return recursion(0,0,c-1,grid,dp);
    }
};