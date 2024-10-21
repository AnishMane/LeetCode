class Solution {
public:
    int subordinateOfHead(int n, int headID, vector<int>& manager, vector<int>& informTime){
        vector<vector<int>> subordinates(n);
        for(int i=0;i<n;i++){
            if(manager[i] != -1)
                subordinates[manager[i]].push_back(i);
        }
        
        return dfs(headID,subordinates,informTime);
    }
    
    int dfs(int curEmp, vector<vector<int>>&subordinates, vector<int>& informTime){
        if(subordinates[curEmp].empty())
            return 0;
        int maxTime = 0;
        for(auto subordinate:subordinates[curEmp]){
            maxTime = max(maxTime,dfs(subordinate,subordinates,informTime));
        }
        return informTime[curEmp] + maxTime;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        return subordinateOfHead(n,headID,manager,informTime);
    }
};