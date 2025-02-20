class Solution {
public:

    string backtracking(int n, string res,unordered_set<string>& hashset){
        if(res.size()==n){
            if(!hashset.count(res)) return res;
            else return "";
        }

        string take0 = backtracking(n,res+'0',hashset);
        string take1 = backtracking(n,res+'1',hashset);

        if(take0 != "") return take0;
        if(take1 != "") return take1;
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> hashset;
        for(string c:nums) hashset.insert(c);
        return backtracking(nums.size(),"",hashset);
    }
};