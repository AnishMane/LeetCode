class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> inDeg(numCourses,0);
        vector<int> topo;
        for(int i=0;i<adj.size();i++){
            for(int j:adj[i]){
                inDeg[j]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<adj.size();i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                inDeg[it]--;
                if(inDeg[it]==0)
                    q.push(it);
            }
        }
        if(topo.size() == numCourses)
            return true;
        return false;
    }
};