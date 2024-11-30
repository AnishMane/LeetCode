class Solution {
public:
    
    vector<string> children(string parent){
        vector<string> result;
        for(int i=0;i<parent.size();i++){
            string temp1 = parent;
            string temp2 = parent;
            char c1 = (((temp1[i]-'0')+1)%10) + '0';
            char c2 = (((temp2[i]-'0')-1+10)%10) + '0';
            temp1[i] = c1;
            temp2[i] = c2;
            result.push_back(temp1);
            result.push_back(temp2);
        }
        return result;
    }
    
    int openLock(vector<string>& deadends, string target) {
        set<string> vis;
        for(string s:deadends){
            vis.insert(s);
        }
        if(vis.count("0000"))
            return -1;
        
        queue<pair<string,int>> q;
        q.push({"0000",0});
        while(!q.empty()){
            string cur = q.front().first;
            int level = q.front().second;
            q.pop();
            if(target == cur)
                return level;
            for(string s:children(cur)){
                if(!vis.count(s)){
                    vis.insert(s);
                    q.push({s,level+1});
                }
            }
        }
        return -1;
    }
};