class Solution {
public:

    int recursion(int i, int j, vector<vector<int>> &matrix, vector<vector<int>>&dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int m = matrix.size();
        int n = matrix[0].size();
        int maxpath = 1;
        
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                if(delrow==0 || delcol==0){
                    int nrow = i + delrow;
                    int ncol = j + delcol;

                    if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && matrix[nrow][ncol]>matrix[i][j]){
                        maxpath = max(maxpath,1 + recursion(nrow,ncol,matrix,dp));
                    }
                }
            }
        }
        return dp[i][j] = maxpath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result = max(result,recursion(i,j,matrix,dp));
            }
        }

        return result;
    }
};