class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> hashMap;

        for(char c:s){
            hashMap[c]++;
        }
        int result = s.size();
        for(auto it:hashMap){
            while(it.second>=3){
                result-=2;
                it.second-=2;
            }
        }
        return result;
    }
};