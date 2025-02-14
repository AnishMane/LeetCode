class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> que;
        unordered_map<char,int> hashMap;

        for(char c: tasks){
            hashMap[c]++;
        }
        for(auto it:hashMap){
            pq.push(it.second);
        }

        int time = 0;
        while(!pq.empty() || !que.empty()){
            time+=1;
            if(!pq.empty()){
                int count = pq.top() - 1;
                pq.pop();
                if(count>0){
                    que.push({count,time+n});
                }
            }
            if(!que.empty() && que.front().second==time){
                int count = que.front().first;
                que.pop();
                pq.push(count);
            }
        }
        return time;
    }
};