class Solution {
public:

    void recursion(int ind, string res, vector<bool>& used, unordered_set<string>& hashset, string pattern){
        if(ind==pattern.size()){
            hashset.insert(res);
            return;
        }

        int prev = res.back() - '0';
        if(pattern[ind]=='I'){
            for(int i=prev;i<=9;i++){
                if(used[i]) continue;
                string temp = to_string(i);
                used[i]=true;
                recursion(ind+1,res+temp,used,hashset,pattern);
                used[i] = false;
            } 
        }
        else{
            for(int i=prev;i>=1;i--){
                if(used[i]) continue;
                string temp = to_string(i);
                used[i]=true;
                recursion(ind+1,res+temp,used,hashset,pattern);
                used[i] = false;
            } 
        }
    }

    string smallestNumber(string pattern) {
        vector<bool> used(10,false);
        unordered_set<string> hashset;
        for(int i=1;i<=9;i++){
            string res = to_string(i);
            used[i] = true;
            recursion(0,res,used,hashset,pattern);
            used[i] = false;
        }
        int mini = INT_MAX;
        for(auto it:hashset){
            mini = min(mini,stoi(it));
        }
        return to_string(mini);
    }
};