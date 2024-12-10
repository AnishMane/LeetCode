class Solution {
public:
    
    struct Compare{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            return a.second < b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        unordered_map<int,int> hashMap;
        for(int num:nums){
            hashMap[num]++;
        }
        for(auto it:hashMap){
            pq.push({it.first,it.second});
        }
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};