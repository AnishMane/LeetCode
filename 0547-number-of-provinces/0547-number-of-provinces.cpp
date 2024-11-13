class Solution {
public:
    void helper(int node, vector<vector<int>>& adj, vector<int>& vis){
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                vis[adj[node][i]] = 1;
                helper(adj[node][i], adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                vis[i] = 1;
                helper(i,adj,vis);
            }
        }
        return count;
    }
};