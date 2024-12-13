class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        int i=0;
        int j=1;
        if(s.size()==0)
            return 0;
        hashSet.insert(s[i]);
        int maxCount =1;
        int count = 1;
        while(j<s.size()){
            if(hashSet.count(s[j])){
                hashSet.clear();
                maxCount = max(maxCount,count);
                count = 1;
                i++;
                j=i+1;
                hashSet.insert(s[i]);
            }
            else{
                count++;
                hashSet.insert(s[j]);
                j++;
            }
        }
        return max(maxCount,count);
    }
};