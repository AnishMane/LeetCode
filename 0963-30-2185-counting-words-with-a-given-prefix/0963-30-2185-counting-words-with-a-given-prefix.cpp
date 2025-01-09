class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string word:words){
            if(pref == word.substr(0,pref.size())){
                count++;
            }
        }
        return count;
    }
};