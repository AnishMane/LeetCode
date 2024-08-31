class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> hashMap;
        for(int i=0;i<words.size();i++)
        {
            for(char c:words[i])
            {
                hashMap[c]++;
            }
        }
        for(auto c:hashMap)
        {
            if(c.second%words.size() != 0)
            {
                return false;
            }
        }
        return true;
    }
};