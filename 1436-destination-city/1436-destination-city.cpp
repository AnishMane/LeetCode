class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<int> temp(2, 0);
        unordered_map<string,vector<int>> hashMap;
        for(int i=0;i<paths.size();i++)
        {
            hashMap[paths[i][0]] = temp;
            hashMap[paths[i][1]] = temp;
        }
        for(int i=0;i<paths.size();i++)
        {
            hashMap[paths[i][0]][0] = 1;
            hashMap[paths[i][1]][1] = 1;
        }
        for(auto str:hashMap)
        {
            if(str.second[0] == 0)
            {
                return str.first;
            }
        }
        return "";
    }
};