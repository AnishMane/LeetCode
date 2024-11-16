class Solution {
private:
    int count = 0;
public:
    
    void bfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>& vis, int delRow[], int delCol[]){
        queue<pair<int,int>> q;
        vis[row][col] = 1;
        q.push({row,col});
        int tempCount = 1;
        bool check = true;
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int s=0;s<4;s++){
                int nrow = i + delRow[s];
                int ncol = j + delCol[s];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        tempCount++;
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
                else if(grid[i][j] == 1){
                    check = false;
                }
            }
        }
        if(check)
            count += tempCount;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(), 0));
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {+1,0,-1,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    bfs(i,j,grid,vis,delRow,delCol);
                }
            }
        }
        return count;
    }
};