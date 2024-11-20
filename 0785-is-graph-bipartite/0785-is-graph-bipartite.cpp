class Solution {
public:
    
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& vis){
        vis[i] = 0;
        queue<pair<int,int>> q;
        q.push({i,0});
        while(!q.empty()){
            int node = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int j=0;j<graph[node].size();j++){
                if(vis[graph[node][j]] == col){
                    return false;
                }
                if(vis[graph[node][j]] == -1){
                    int ncol = 1-col;
                    vis[graph[node][j]] = ncol;
                    q.push({graph[node][j],ncol});
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i] == -1){
                if(!bfs(i,graph,vis))
                    return false;
            }
        }
        return true;
    }
};