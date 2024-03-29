class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int i = 0;
        int j=0;
        while(i<word1.size() && j<word2.size())
        {
            if(i==j)
            {
                merged+=word1[i];
                i++;
                continue;
            }
            if(i>j)
            {
                merged+=word2[j];
                j++;
                continue;
            }
        }
        while(i<word1.size())
        {
            merged+=word1[i];
            i++;
        }
        while(j<word2.size())
        {
            merged+=word2[j];
            j++;
        }
        return merged;
    }
};