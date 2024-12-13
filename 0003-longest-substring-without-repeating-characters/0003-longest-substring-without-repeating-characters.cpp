class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0;
        int j =0;
        set<int> st;
        int maxcount=0;
        
        while(j<s.length()){
            
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
                j++;
                maxcount = max(maxcount,j-i);
            }
            else{
                st.erase(s[i]);
                i++;
            }
            
        }
        
        return maxcount;
        
    }
};