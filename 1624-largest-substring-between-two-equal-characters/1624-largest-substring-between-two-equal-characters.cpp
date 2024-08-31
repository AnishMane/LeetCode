class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,vector<int>> hashMap;
        for(int i=0;i<s.size();i++)
        {
            hashMap[s[i]].push_back(i);
        }
        
        int maxLength = -1;
        for(auto c:hashMap)
        {
            if(c.second.size() > 1){
                for(int i=1;i<c.second.size();i++)
                    {
                        maxLength = max(maxLength, c.second[i] - c.second[0]-1);
                }
            }
        }
        return maxLength;
    }
};