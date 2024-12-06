class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int, int>>& island, int delRow[], int delCol[]) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 2;
        island.push_back({i, j});
        
        for (int s = 0; s < 4; s++) {
            int nrow = i + delRow[s];
            int ncol = j + delCol[s];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, island, delRow, delCol);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
        
        vector<pair<int, int>> firstIsland;
        
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, firstIsland, delRow, delCol);
                    found = true;
                }
            }
        }
        
        queue<pair<int, int>> q;
        for (auto& cell : firstIsland) {
            q.push(cell);
        }
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int s = 0; s < 4; s++) {
                    int nrow = x + delRow[s];
                    int ncol = y + delCol[s];
                    
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                        if (grid[nrow][ncol] == 1) {
                            return steps;
                        }
                        if (grid[nrow][ncol] == 0) {
                            grid[nrow][ncol] = 2;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
