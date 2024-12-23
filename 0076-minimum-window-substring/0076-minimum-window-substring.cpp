class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        unordered_map<char,int> hashMap;
        unordered_map<char,int> window;
        
        for(char c:t){
            hashMap[c]++;
        }
        int have = 0;
        int need = hashMap.size();
        int res[] = {-1,-1};
        int resLen = INT_MAX;
        int l = 0;
        for(int r=0;r<s.size();r++){
            char c = s[r];
            window[c]++;
            
            if(hashMap.count(c) && window[c] == hashMap[c])
                have++;
            
            while(have == need){
                if(r-l+1 < resLen){
                    res[0] = l;
                    res[1] = r;
                    resLen = r-l+1;
                }
                window[s[l]]--;
                
                if(hashMap.count(s[l]) && window[s[l]] < hashMap[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen==INT_MAX? "" : s.substr(res[0],resLen);
    }
};