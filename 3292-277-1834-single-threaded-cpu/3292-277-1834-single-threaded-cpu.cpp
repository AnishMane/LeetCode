class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;
        long long time = tasks[0][0];
        int ind = 0;
        vector<int> res;
        while(ind<n || !minheap.empty()){
            while(ind<n && tasks[ind][0]<=time){
                minheap.push({tasks[ind][1],tasks[ind][2]});
                ind++;
            }
            if(minheap.empty()){
                time = tasks[ind][0];
            }
            else{
                vector<int> head = minheap.top();
                time+=head[0];
                res.push_back(head[1]);
                minheap.pop();
            }
        }
        return res;
    }
};