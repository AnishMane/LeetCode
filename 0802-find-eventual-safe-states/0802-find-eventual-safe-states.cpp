class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rev(graph.size());
        vector<int> inDeg(graph.size(), 0);
        for(int i=0;i<graph.size();i++){
            for(int it:graph[i]){
                rev[it].push_back(i);
                inDeg[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(inDeg[i] == 0)
                q.push(i);
        }
        
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it:rev[node]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};