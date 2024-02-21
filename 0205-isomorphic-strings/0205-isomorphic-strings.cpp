class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,vector<int>> table1;
        unordered_map<char,vector<int>> table2;
        for(int i=0;i<s.size();i++)
        {
            table1[s[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++)
        {
            table2[t[i]].push_back(i);
        }
        vector<vector<int>> temp1;
        vector<vector<int>> temp2;
        for(auto c:table1)
        {
            temp1.push_back(c.second);
        }
        for(auto c:table2)
        {
            temp2.push_back(c.second);
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1 == temp2)
        {
            return true;
        }
        return false;
    }
};