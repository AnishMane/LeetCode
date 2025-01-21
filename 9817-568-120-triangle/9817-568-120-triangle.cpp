class Solution {
public:
    
    int recursion(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        if(i==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = triangle[i][j] + recursion(i+1,j,triangle,dp);
        int right = triangle[i][j] + recursion(i+1,j+1,triangle,dp);
        
        dp[i][j] = min(left,right);
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(0,0,triangle,dp);
    }
};