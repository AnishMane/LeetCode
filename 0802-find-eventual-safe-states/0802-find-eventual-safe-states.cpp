class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(int i=0;i<graph[node].size();i++){
            if(!vis[graph[node][i]]){
                if(dfs(graph[node][i],graph,vis,pathVis,check)){
                    return true;
                }
            }
            else if(pathVis[graph[node][i]])
                return true;
        }
        check[node]=1;
        pathVis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> pathVis(graph.size(),0);
        vector<int> check(graph.size(),0);
        vector<int> result;
        
        for(int i=0;i<graph.size();i++){
                if(!vis[i]){
                    dfs(i,graph,vis,pathVis,check);
                }
        }
        for(int i=0;i<graph.size();i++){
            if(check[i] == 1){
                result.push_back(i);
            }
        }
        return result;
    }
};