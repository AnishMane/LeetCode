class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<int> dp(n);
        for(int j=0;j<n;++j){
            dp[j] = matrix[0][j];
        }
        
        for(int i=1;i<n;++i){
            vector<int> cur(n);
            for(int j=0;j<n;++j){
                int up = matrix[i][j] + dp[j];
                int left = 1e9;
                int right = 1e9;
                if(j>0) left = matrix[i][j] + dp[j-1]; 
                if(j<n-1) right = matrix[i][j] + dp[j+1];
                
                cur[j] = min(up,min(left,right));
            }
            dp=cur;
        }
        
        int minSum = INT_MAX;
        for(int i=0;i<n;++i){
            minSum = min(minSum, dp[i]);
        }
        return minSum;
    }
};