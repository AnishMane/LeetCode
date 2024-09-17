class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hashMap1;
        unordered_map<string,int> hashMap2;
        
        string temp = "";
        for(int i=0;i<s1.size();++i){
            if(s1[i] == ' '){
                hashMap1[temp]++;
                temp = "";
                continue;
            }
            temp += s1[i];
        }
        if(temp.length() != 0){
            hashMap1[temp]++;
        }
        temp ="";
        for(int i=0;i<s2.size();++i){
            if(s2[i] == ' '){
                hashMap2[temp]++;
                temp = "";
                continue;
            }
            temp += s2[i];
        }
        if(temp.length() != 0){
            hashMap2[temp]++;
        }
        vector<string> result;
        for(auto s:hashMap1){
            if(s.second == 1 && !(hashMap2.find(s.first) != hashMap2.end())){
                result.push_back(s.first);
            }
        }
        for(auto s:hashMap2){
            if(s.second == 1 && !(hashMap1.find(s.first) != hashMap1.end())){
                result.push_back(s.first);
            }
        }
        return result;
    }
};