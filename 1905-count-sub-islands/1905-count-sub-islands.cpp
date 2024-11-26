class Solution {
public:
    
    bool dfs(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int delRow[], int delCol[]){
        vis[x][y] = 1;
        int n = grid2.size();
        int m = grid2[0].size();
        bool isSubIsland = grid1[x][y] == 1;
        for(int i=0;i<4;i++){
            int nrow = x + delRow[i];
            int ncol = y + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid2[nrow][ncol] == 1){
                if(!dfs(nrow,ncol,grid1,grid2,vis,delRow,delCol)){
                    isSubIsland = false;
                }
            }
        }
        return isSubIsland;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> vis(grid2.size(), vector<int>(grid2[0].size(),0));
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        int result = 0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(!vis[i][j] && grid2[i][j] == 1){
                    if(dfs(i,j,grid1,grid2,vis,delRow,delCol)){
                        result++;
                    }
                }
            }
        }
        return result;
    }
};