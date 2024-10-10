class Solution {
public:
    void combinations(int i, int t, vector<int> &candidates, vector<vector<int>> &result, vector<int> &res){
            if(t == 0){
                result.push_back(res);
                return;
            }
        for(int j = i;j<candidates.size();j++){
            if(j>i && candidates[j] == candidates[j-1])
                continue;
            if(candidates[j] > t)
                break;
            res.push_back(candidates[j]);
            combinations(j+1,t-candidates[j],candidates,result, res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> res;
        combinations(0,target,candidates,result,res);
        return result;
    }
};