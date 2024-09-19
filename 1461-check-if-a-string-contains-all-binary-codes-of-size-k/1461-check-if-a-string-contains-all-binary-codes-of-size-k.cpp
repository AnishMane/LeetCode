class Solution {
public:   
    bool hasAllCodes(string s, int k) {
        set<string> st;
        if(k>s.size()){
            return false;
        }
        for(int i=0;i<s.size()-k+1;++i){
            string temp = s.substr(i,k);
            st.insert(temp);
        }
        
        if(st.size()!= pow(2,k)){
            return false;
        }
        return true;
    }
};