class Solution {
public:
    
    unordered_map<int,int> dp;

    int dfs(vector<int>&nums, int target){
        if(dp.count(target)) return dp[target];

        int res = 0;
        for(int num:nums){
            if(target<num) break;
            res+=dfs(nums,target-num);
        }

        return dp[target] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dp[0] = 1;
        return dfs(nums,target);
    }
};