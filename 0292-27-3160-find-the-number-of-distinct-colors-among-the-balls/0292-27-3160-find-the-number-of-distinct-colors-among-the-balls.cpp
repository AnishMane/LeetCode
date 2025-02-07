class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> hashMap;
        unordered_set<int> hashSet;
        vector<int> result;

        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(hashMap.find(x)!=hashMap.end()){
                int oldColor = hashMap[x];
                int count = 0;
                for(auto it:hashMap){
                    if(it.second==oldColor) count++;
                }
                if(hashSet.count(oldColor) && count==1){
                    hashSet.erase(oldColor);
                }
            }

            hashMap[x] = y;
            hashSet.insert(y);

            result.push_back(hashSet.size());
        }
        return result;
    }
};