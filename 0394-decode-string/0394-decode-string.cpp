class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string result = "";
        for(int i=0;i<s.size();++i){
            if(s[i] == ']'){
                string main = "";
                string temp = "";
                while(st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && st.top() - '0'>=0 && st.top() - '0' < 10 ){
                    num = st.top() + num;
                    st.pop();
                }
                int newNum = stoi(num);
                for(int j=0;j<newNum;++j){
                    main += temp;
                }
                for(char c:main){
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};