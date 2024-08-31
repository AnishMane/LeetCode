class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26,0);
        for(auto &word:words)
        {
            for(char c:word){
                freq[c-'a']++;
            }
        }
        
        for(int i =0;i<26;i++)
        {
            if(freq[i]&&freq[i]%words.size() !=0)
            {
                return false;
            }
        }
        return true;
    }
};