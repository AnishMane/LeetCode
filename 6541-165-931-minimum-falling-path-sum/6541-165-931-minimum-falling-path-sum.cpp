class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;++j){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<n;++i){
            for(int j=0;j<n;++j){
                int up = matrix[i][j] + dp[i-1][j];
                int left = 1e9;
                int right = 1e9;
                if(j>0) left = matrix[i][j] + dp[i-1][j-1]; 
                if(j<n-1) right = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up,min(left,right));
            }
        }
        
        int minSum = INT_MAX;
        for(int i=0;i<n;++i){
            minSum = min(minSum, dp[n-1][i]);
        }
        return minSum;
    }
};