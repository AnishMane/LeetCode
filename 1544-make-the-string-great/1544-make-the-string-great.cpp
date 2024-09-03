class Solution {
public:
    string makeGood(string s) {
        string result = "";
        stack<char> st;
        for(int i=s.size()-1;i>=0;--i){
            st.push(s[i]);
        }
        while(!st.empty()){
            if(result.size() >0 && result[result.size()-1] != st.top() && tolower(result[result.size()-1]) == tolower(st.top())){
                result.pop_back();
                st.pop();
            }
            else{
                result += st.top();
                st.pop();
            }
        }
        return result;
    }
};