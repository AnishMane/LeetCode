class Solution {
public:
    
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& vis){
        vis[node] = col;
        for(int j=0;j<graph[node].size();j++){
            if(vis[graph[node][j]] == col)
                return false;
            if(vis[graph[node][j]] == -1){
                if(!dfs(graph[node][j], 1-col, graph,vis))
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        
        for(int i=0;i<graph.size();i++){
            if(vis[i] == -1){
                if(!dfs(i,0,graph,vis))
                    return false;
            }
        }
        return true;
    }
};