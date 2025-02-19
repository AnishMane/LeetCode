class Solution {
public:

    void recursion(int ind, string res, int n, set<string>& result){
        if(ind>n){
            result.insert(res);
            return;
        }
        for(int i=0;i<=2;i++){
            char temp = 'a' + i;
            if(res=="") recursion(ind+1,res+temp,n,result);
            else if(res.back()==temp) continue;
            recursion(ind+1,res+temp,n,result);
        }
    }

    string getHappyString(int n, int k) {
        set<string> result;
        recursion(1,"",n,result);
        if(k-1 >= result.size()) return "";
        for(auto it:result){
            if(k!=1){
                k--;
                continue;
            }
            else if(k==1) return it;
        }
        return "";
    }
};