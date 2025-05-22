class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        
        for(int n:nums){
            vector<vector<int>> new_perms;
            for(auto& p:perms){
                for(int i=0;i<=p.size();i++){
                    vector<int> copy = p;
                    copy.insert(copy.begin()+i,n);
                    new_perms.push_back(copy);
                }
            }
            perms = new_perms;
        }
        return perms;
    }
};