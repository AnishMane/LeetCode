class Solution {
public:
    void permutations(int i, vector<int>&nums,vector<vector<int>>& result, vector<int>&res, vector<bool>& freq){
        if(i==nums.size()){
            result.push_back(res);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(freq[j])
                continue;
            res.push_back(nums[j]);
            freq[j] = true;
            permutations(i+1,nums,result,res,freq);
            res.pop_back();
            freq[j] = false;

        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> freq(nums.size(),false);
        vector<vector<int>> result;
        vector<int> res;
        permutations(0,nums,result,res,freq);
        return result;
    }
};