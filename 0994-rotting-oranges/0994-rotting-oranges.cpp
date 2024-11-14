class Solution {
public:
    
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }
        int n = grid.size();
        int m = grid[0].size();
        int maxT = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            maxT = max(t,maxT);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = x + delRow[i];
                int ncol = y + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol}, t+1});
                }
            }
        }
        if(vis != grid)
            return -1;
        
        return maxT;
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int delRow[] = {0,+1,0,-1};
        int delCol[] = {-1,0,+1,0};
        return bfs(grid,vis,delRow,delCol);
    }
};