class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& result, vector<vector<int>>& image,  int color, int delRow[], int delCol[], int initial){
        result[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && image[nrow][ncol] == initial && result[nrow][ncol]!=color){
                dfs(nrow,ncol,result,image,color,delRow,delCol,initial);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        vector<vector<int>> result = image;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        dfs(sr,sc,result,image, color, delRow, delCol, initial);
        return result;
    }
};