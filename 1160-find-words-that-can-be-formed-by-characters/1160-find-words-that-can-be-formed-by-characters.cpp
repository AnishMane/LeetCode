class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> table;
        for(char c:chars)
        {
            table[c]++;
        }
        int sum = 0;
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,int> temp;
            for(char c:words[i])
            {
                temp[c]++;
            }
            bool check = true;
            for(auto j=temp.begin();j!=temp.end();j++)
            {
                if(table[j->first] < j->second)
                {
                    check = false;
                }
            }
            if(check == true)
            {
                sum = sum+words[i].size();
            }
        }
        return sum;
    }
};