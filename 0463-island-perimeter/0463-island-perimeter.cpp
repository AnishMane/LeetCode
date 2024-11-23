class Solution {
private:
    int perimeter = 0;
public:
    
    void dfs(int x,int y, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
        vis[x][y] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int curPer = 0;
        for(int i=0;i<4;i++){
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m){
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    curPer++;
                    dfs(nrow,ncol,grid,vis,delRow,delCol);
                }
                else if(vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    curPer++;
                }
            }
        }
        perimeter = perimeter + 4 - curPer;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int delRow[]= {0,+1,0,-1};
        int delCol[]= {+1,0,-1,0};
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i,j,grid,vis,delRow,delCol);
                }
            }
        }
        return perimeter;
    }
};