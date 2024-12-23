class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> hashMap;
        hashMap['('] = ')';
        hashMap['{'] = '}';
        hashMap['['] = ']';
        
       for(char c:s){
           if(c=='(' || c=='{' || c=='['){
               st.push(c);
               continue;
            }
               
           if(st.empty() || hashMap[st.top()] != c )
               return false;
           else{
                st.pop();
                continue;
            }     
         }
        if(!st.empty())
            return false;
        return true;
    }
};