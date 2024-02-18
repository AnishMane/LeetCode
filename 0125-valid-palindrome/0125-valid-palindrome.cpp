class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
            }
        }
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            while(i<j && !isalnum(s[i]))
            {
                i++;
            }
            while(i<j && !isalnum(s[j]))
            {
                j--;
            }
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};