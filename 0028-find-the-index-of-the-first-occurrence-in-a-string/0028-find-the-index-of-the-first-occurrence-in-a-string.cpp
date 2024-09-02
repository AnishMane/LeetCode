class Solution {
public:
    int strStr(string haystack, string needle) {
        unordered_map<string,int> hashMap;
        if(haystack.size() < needle.size()){
            return -1;
        }
        for(int i=0;i<=haystack.size()-needle.size();i++){
            string temp = "";
            for(int j=0;j<needle.size();j++){
                temp+=haystack[i+j];
            }
            if(hashMap.find(temp) != hashMap.end()){
                continue;
            }else{
                hashMap[temp] = i;
            }
        }
        if(hashMap.find(needle)!= hashMap.end()){
            return hashMap[needle];
        }
        return -1;
    }
};