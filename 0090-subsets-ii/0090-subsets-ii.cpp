class Solution {
public:
    void subset(int i, vector<int>& nums, vector<vector<int>>& result, vector<int>& res){
        result.push_back(res);

        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j] == nums[j-1])
                continue;
            res.push_back(nums[j]);
            subset(j+1,nums,result,res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> res;
        sort(nums.begin(),nums.end());
        subset(0,nums,result,res);
        return result;
    }
};