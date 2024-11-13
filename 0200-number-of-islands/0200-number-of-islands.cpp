class Solution {
public:
    
    void helper(pair<int,int>node, vector<vector<char>>& grid, vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push(node);
        vis[node.first][node.second] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int delrow = -1; delrow<=1;delrow++){
                for(int delcol = -1; delcol<=1;delcol++){
                    if(delrow == 0 || delcol == 0){
                        int nrow = i + delrow;
                        int ncol = j + delcol;
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                            if(grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    helper({i,j}, grid, vis);
                }
            }
        }
        return count;
    }
};