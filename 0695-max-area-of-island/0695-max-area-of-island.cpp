class Solution {
private:
    int count;
public:
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                count++;
                dfs(nrow,ncol,grid,vis,delRow,delCol);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int delRow[] = {0,+1,0,-1};
        int delCol[] = {-1,0,+1,0};
        
        int result = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count = 1;
                    dfs(i,j,grid,vis,delRow,delCol);
                    result = max(result,count);
                }
            }
        }
        return result;
    }
};