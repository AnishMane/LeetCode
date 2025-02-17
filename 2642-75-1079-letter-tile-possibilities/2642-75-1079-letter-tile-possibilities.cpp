class Solution {
public:

    void recursion(string res,string tiles, vector<bool>& used, unordered_set<string>& sequence){
        if(res.size()>tiles.size()) return; 
        if(res.size()>0) sequence.insert(res);

        for(int i=0;i<tiles.size();i++){
            if(used[i]) continue;
            used[i] = true;
            recursion(res+tiles[i],tiles,used,sequence);
            used[i] = false;
        }
        return;
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> used(n,false);
        unordered_set<string> sequence;
        recursion("",tiles,used,sequence);
        return sequence.size();
    }
};