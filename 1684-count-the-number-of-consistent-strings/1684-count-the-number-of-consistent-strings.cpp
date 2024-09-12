class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count =0;
        unordered_set<char> hashSet;
        
        for(int i=0;i<allowed.size();++i){
            hashSet.insert(allowed[i]);    
        }
        for(int i=0;i<words.size();++i){
            bool checker = true;
            for(int j=0;j<words[i].size();++j){
                if(!hashSet.count(words[i][j])){
                    checker = false;
                }
            }
            count += checker ? 1 : 0;
        }
        return count;
    }
};