class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        
        for(int num:nums){
            hashMap[num]++;
        }
        
        for(auto it:hashMap){
            pq.push({it.second, it.first});
        }
        
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};