class Solution {
public:
    string removeOccurrences(string s, string part) {
        string st="";
        int psize = part.size();

        for(char c:s){
            st.push_back(c);
            if(st.size()>=psize && st.substr(st.size()-psize,psize)==part){
                st.erase(st.size()-psize);
            }
        }
        return st;
    }
};