class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> str1(26,0);
        vector<int> str2(26,0);

        for(int i=0;i<s1.size();i++){
            str1[s1[i] - 'a']++;
            str2[s2[i] - 'a']++;
        }
        
        int window = s1.size();
        int i=0;
        int j=window;
        
        while(j<s2.size()){
            if(str1==str2)
                return true;
            str2[s2[j] - 'a']++;
            str2[s2[i] - 'a']--;
            i++;
            j++; 
        }
        if(str1==str2)
            return true;
        return false;
    }
};