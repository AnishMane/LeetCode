class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size() < 10){
            return {};
        }
        unordered_map<string,int> hashMap;
        for(int i=0;i<s.size()-9;++i){
            string temp = s.substr(i,10);
            hashMap[temp]++;
        }
        for(auto st:hashMap){
            if(st.second>1){
                result.push_back(st.first);
            }
        }
        return result;
    }
};