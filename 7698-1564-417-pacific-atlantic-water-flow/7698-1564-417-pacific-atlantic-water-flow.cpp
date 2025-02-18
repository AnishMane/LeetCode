class Solution {
public:

    void bfs(pair<int,int>point,set<pair<int,int>>&ocean, vector<vector<int>>& vis, vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();
        queue<pair<int,int>> q;
        vis[point.first][point.second] = 1;
        ocean.insert(point);
        q.push(point);

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
                            if(!vis[nrow][ncol] && heights[nrow][ncol]>=heights[x][y]){
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                                ocean.insert({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> vis1(m,vector<int>(n,0));
        vector<vector<int>> vis2(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    if(!vis1[i][j]){
                        bfs({i,j},pacific,vis1,heights);
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==m-1 || j==n-1){
                    if(!vis2[i][j]){
                        bfs({i,j},atlantic,vis2,heights);
                    }
                }
            }
        }

        vector<vector<int>> result;
        for(auto it:pacific){
            if(atlantic.count(it)) result.push_back({it.first,it.second});
        }
        return result;
    }
};