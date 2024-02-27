class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> table;
        table['('] = ')';
        table['{'] = '}';
        table['['] = ']';
        
        for(char c:s)
        {
            if(st.empty())
            {
                st.push(c);
                continue;
            }
            if(c == table[st.top()])
            {
                st.pop();
                continue;
            }
            else{
                st.push(c);
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
    }
};