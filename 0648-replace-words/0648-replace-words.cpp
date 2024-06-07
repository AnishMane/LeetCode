class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict;
        for(string s:dictionary)
        {
            dict.insert(s);
        }
        string s;
        vector<string> group;
        stringstream ss(sentence);
        string result = "";
        while(getline(ss, s, ' '))
        {
            group.push_back(s);
        }
        
        for(int i=0;i<group.size();i++)
        {
            s = "";
            bool check = false;
            for(char c: group[i])
            {
                s = s + c;
                if(dict.find(s) != dict.end())
                {
                    check = true;
                    result = result + s;
                    break;
                }
            }
            if(!check)
            {
                result += s;
            }
            if(i!= group.size()-1)
            {
                result += " ";
            }
            
        }
        return result;
    }
};