class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict;
        for(string s:wordList){
            dict.insert(s);
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string top = q.front().first;
            int level = q.front().second;
            q.pop();
            for(int i=0;i<top.size();i++){
                for(int j=0;j<26;j++){
                    string temp = top;
                    if(temp[i]!=j+'a')
                        temp[i] = j + 'a';
                    if(dict.count(temp)){
                        if(temp == endWord)
                            return level+1;
                        dict.erase(temp);
                        q.push({temp,level+1});
                    }
                }
            }
        }
        return 0;
    }
};