class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int index[26] = {0};
        int result = -1;
        for(int i=0;i<s.size();i++)
        {
            index[s[i]-'a'] = i;
        }
        for(int i=0;i<s.size();i++)
        {
            result = max(result, index[s[i]-'a']-i-1);
        }
        return result;
    }
};