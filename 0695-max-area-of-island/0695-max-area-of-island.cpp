class Solution {
private:
    int result = 0;
public:
    
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
        queue<pair<int,int>>q;
        vis[i][j] = 1;
        q.push({i,j});
        int count = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int s=0;s<4;s++){
                int nrow = row + delRow[s];
                int ncol = col + delCol[s];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    count++;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        result = max(result,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(), 0));
        int delRow[] = {0,+1,0,-1};
        int delCol[] = {-1,0,+1,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j] == 1)
                    bfs(i,j,grid,vis,delRow,delCol);
            }
        }
        return result;
    }
};