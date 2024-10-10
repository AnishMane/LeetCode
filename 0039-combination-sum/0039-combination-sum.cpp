class Solution {
private:
    vector<vector<int>> result;
public:
    void combinations(int i, int t, vector<int> candidates, vector<int> res){
        if(i==candidates.size()){
            if(t==0){
            result.push_back(res);
        }
            return;
        }
        if(candidates[i] <= t){
            res.push_back(candidates[i]);
            combinations(i,t-candidates[i],candidates,res);
            res.pop_back();
        }
        
        combinations(i+1,t,candidates,res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;
        combinations(0,target,candidates,res);
        return result;
    }
};