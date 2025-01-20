class Solution {
public:
    
    void backtracking(int index, vector<vector<string>> &result, vector<string> &part, string s){
        if(index>=s.length()){
            result.push_back(part);
            return;
        }
        
        for(int j=index;j<s.size();++j){
            if(isPali(s,index,j)){
                part.push_back(s.substr(index,j-index+1));
                backtracking(j+1,result,part,s);
                part.pop_back();
            }
        }
    }
    
    bool isPali(string s, int i, int j){
        string temp = s.substr(i,j-i+1);
        reverse(temp.begin(),temp.end());
        return temp==s.substr(i,j-i+1);
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        
        backtracking(0,result,part,s);
        
        return result;
    }
};