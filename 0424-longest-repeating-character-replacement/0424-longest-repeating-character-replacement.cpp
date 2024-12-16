class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() < 2){
            return s.size();
        }
        int i=0;
        int j=1;
        int result = 0;
        int maxi = 0;
        unordered_map<char,int> hashMap;
        hashMap[s[i]]++;
        
        while(i<j && j<s.size()){
            hashMap[s[j]]++;
            maxi = max(maxi,hashMap[s[j]]);
            if(j-i+1-maxi > k){
                hashMap[s[i]]--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};