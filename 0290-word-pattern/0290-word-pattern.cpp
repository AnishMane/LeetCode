class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> cToS;
        unordered_map<string,char> sToC;
        
        stringstream ss(s);
        vector<string> words;
        string word;
        while(getline(ss,word, ' '))
        {
            words.push_back(word);
        }
        if(pattern.size()!=words.size())
        {
            return false;
        }
        
        for(int i=0;i<pattern.size();i++)
        {
            char c = pattern[i];
            string w = words[i];
            if(cToS.count(c) && cToS[c] != w)
                return false;
            if(sToC.count(w) && sToC[w] != c)
                return false;
            cToS[c] = w;
            sToC[w] = c;
        }
        return true;
        
    }
};