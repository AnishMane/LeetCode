class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n);
        for(auto it:trust){
            adj[it[0]-1].push_back(it[1]-1);
        }
        vector<int> inDeg(n,0);
        vector<int> outDeg(n,0);
        for(int i=0;i<adj.size();i++){
            for(int j: adj[i]){
                outDeg[i]++;
                inDeg[j]++;
            }
        }
        for(int i=0;i<n;i++){
            if(inDeg[i] == n-1 && outDeg[i] == 0)
                return i+1;
        }
        return -1;
    }
};