class NumMatrix {
private:
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return;
        int cols = matrix[0].size();
        
        prefixSum.resize(rows, vector<int>(cols, 0));
        
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                int top = (i>0) ? prefixSum[i-1][j] : 0;
                int left = (j>0) ? prefixSum[i][j-1] : 0;
                int topLeft = (i>0 && j>0)  ? prefixSum[i-1][j-1] : 0;
                prefixSum[i][j] = matrix[i][j] + top + left - topLeft;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefixSum[row2][col2];
        int top = row1>0 ? prefixSum[row1-1][col2] : 0;
        int left = col1>0 ? prefixSum[row2][col1-1]:0;
        int topLeft = (row1>0 && col1>0) ? prefixSum[row1-1][col1-1] : 0;
        return total - top -left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */