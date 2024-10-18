class Solution {
public:
    
    int dfs(int cur, int par, unordered_map<int,vector<int>>& hashMap, vector<bool>& hasApple){
        int time = 0;
        vector<int> child = hashMap[cur];
        for(int i=0;i<child.size();i++){
            if(child[i]==par)continue;
            int childTime = dfs(child[i],cur,hashMap,hasApple);
            if(childTime!=0 || hasApple[child[i]])
                time+= childTime+2;
        }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<edges.size();i++){
            hashMap[edges[i][0]].push_back(edges[i][1]);
            hashMap[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,-1,hashMap,hasApple);
    }
};