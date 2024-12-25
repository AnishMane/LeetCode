class Solution {
public:
    void backtracking(int open, int closed,int n, string&s, vector<string>& result){
        if(open == closed && open==n){
            result.push_back(s);
            return;
        }
        if(open<n){
            s+='(';
            backtracking(open+1,closed,n,s,result);
            s.pop_back();
        }
        
        if(closed<open){
            s+=')';
            backtracking(open,closed+1,n,s,result);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> result;
        backtracking(0,0,n,s,result);
        return result;
    }
};