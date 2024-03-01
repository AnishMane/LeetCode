class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        unordered_map<char,int> table;
        for(char c:s)
        {
            table[c]++;
        }
        string result = "";
        while(table['1'] > 1)
        {
            result.push_back('1');
            table['1']--;
        }
        while(table['0'] >0)
        {
            result.push_back('0');
            table['0']--;
        }
        result.push_back('1');
        return result;
    }
};