class Solution {
public:
    
    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int delRow[], int delCol[]){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        bool check = true;
        int n = board.size();
        int m = board[0].size();
        
        vector<pair<int,int>> cellsToFlip;
        cellsToFlip.push_back({row,col});
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int s=0;s<4;s++){
                int nrow = i + delRow[s];
                int ncol = j + delCol[s];
                
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol < m){
                    if(board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                        cellsToFlip.push_back({nrow,ncol});
                    }
                }
                else {
                    check = false;
                }
            }
        }
        if(check){
            for(auto& cell:cellsToFlip){
                board[cell.first][cell.second] = 'X';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(), 0));
        int delRow[] = {0,+1,0,-1};
        int delCol[] = {-1,0,+1,0};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    bfs(i,j,board,vis,delRow,delCol);
                }
            }
        }
    }
};