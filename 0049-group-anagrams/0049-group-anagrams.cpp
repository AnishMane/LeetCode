class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        for(int i=0;i<strs.size();i++)
        {   
            sort(temp[i].begin(),temp[i].end());
        }
        unordered_map<string,vector<int>> table;
        for(int i=0;i<temp.size();i++)
        {
            table[temp[i]].push_back(i);
        }
        vector<vector<string>> result;
        for(auto str:table)
        {
            vector<string> temp2;
            for(int i=0;i<str.second.size();i++)
            {
                temp2.push_back(strs[str.second[i]]);
            }
            result.push_back(temp2);
        }
        return result;
    }
};