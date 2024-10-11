class Solution {
public:
    void permutations(int i, vector<int>&nums,vector<vector<int>>& result, vector<int>&res, unordered_map<int,bool>&hashMap){
        if(i==nums.size()){
            result.push_back(res);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(hashMap[nums[j]])
                continue;
            res.push_back(nums[j]);
            hashMap[nums[j]] = true;
            permutations(i+1,nums,result,res,hashMap);
            res.pop_back();
            hashMap[nums[j]] = false;

        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool> hashMap;
        for(int num:nums){
            hashMap[num] = false;
        }
        vector<vector<int>> result;
        vector<int> res;
        permutations(0,nums,result,res,hashMap);
        return result;
    }
};