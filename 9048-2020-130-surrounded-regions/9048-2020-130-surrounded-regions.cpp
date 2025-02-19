class Solution {
public:

    void bfs(pair<int,int> point, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        vis[point.first][point.second] = 1;
        q.push(point);
        vector<pair<int,int>> cellflip;
        cellflip.push_back(point);
        bool check = true;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    if(delrow==0 || delcol==0){
                        int nrow = x + delrow;
                        int ncol = y + delcol;

                        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                            if(!vis[nrow][ncol] && board[nrow][ncol]=='O'){
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                                cellflip.push_back({nrow,ncol});
                            }
                        }
                        else{
                            check=false;
                        }
                    }
                    
                }
            }
        }

        if(check){
            for(auto it:cellflip){
                board[it.first][it.second] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    bfs({i,j},board,vis);
                }
            }
        }
    }
};