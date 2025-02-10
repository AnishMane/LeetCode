class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char c:s){
            if(!st.empty() && st.top()>='a' && st.top()<='z' && c>='0' && c<='9'){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};