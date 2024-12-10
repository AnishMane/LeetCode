class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        for(int num:nums){
            hashMap[num]++;
        }
        
        int n=nums.size();
        vector<vector<int>> buckets(n+1);
        
        for(auto it:hashMap){
            buckets[it.second].push_back(it.first);
        }
        vector<int> result;
        for(int i=n;i>0 && result.size()<k;i--){
            for(int num:buckets[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};