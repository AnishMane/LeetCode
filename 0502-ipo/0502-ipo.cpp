class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> projects;
        for(int i=0;i<profits.size();i++){
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(),projects.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        priority_queue<int> maxHeap;
        int currentCapital = w;
        int index =0;
        for(int i=0;i<k;i++)
        {
            while(index<projects.size() && projects[index].first <= currentCapital)
            {
                maxHeap.push(projects[index].second);
                index++;
            }
            
            if(maxHeap.empty())
            {
                break;
            }
            
            currentCapital += maxHeap.top();
            maxHeap.pop();
        }
        return currentCapital;
    }
};