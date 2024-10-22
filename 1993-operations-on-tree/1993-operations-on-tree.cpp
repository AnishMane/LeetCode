class LockingTree {
private:
    unordered_map<int,vector<int>> hashMap;
    unordered_map<int,pair<int,bool>> checker;
    vector<int> root;
public:
    LockingTree(vector<int>& parent) {
        root = parent;
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=-1)
                hashMap[parent[i]].push_back(i);
            checker[i] = {-1,false};
        }
    }
    
    bool lock(int num, int user) {
        if(checker[num].second == false){
            checker[num] = {user,true};
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(checker[num].first == user && checker[num].second == true){
            checker[num] = {-1,false};
            return true;
        }
        return false;
    }
    
    bool helper(int node){
        bool check = false;
        if(checker[node].second){
            check = true;
            checker[node] = {-1,false};
        }
        for(int child:hashMap[node]){
            check |= helper(child);
        }
        return check;
    }
    
    bool upgrade(int num, int user) {
        if(checker[num].second == true)return false;
        
        int ancestor = num;
        while(ancestor != -1){
            if(checker[ancestor].second == true)return false;
            ancestor = root[ancestor];
        }
        
        if(!helper(num))return false;
        
        checker[num] = {user,true};
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */