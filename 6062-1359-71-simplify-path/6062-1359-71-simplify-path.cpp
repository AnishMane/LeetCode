class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur = "";
        for (char c : path + "/") {
            if (c == '/') {
                if (cur == "..") {
                    if (!st.empty()) st.pop_back();
                } else if (!cur.empty() && cur != ".") {
                    st.push_back(cur);
                }
                cur.clear();
            } else {
                cur += c;
            }
        }
        string res = "/";
        for (int i = 0; i < st.size(); ++i) {
            if (i > 0) res += "/";
            res += st[i];
        }
        return res;
    }
};