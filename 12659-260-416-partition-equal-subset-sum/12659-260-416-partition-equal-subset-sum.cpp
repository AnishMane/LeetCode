class Solution {
public:
    
    bool recursion(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return nums[ind]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool nottake = recursion(ind-1,target,nums,dp);
        bool take = false;
        if(target>=nums[ind]) take = recursion(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = take | nottake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int num:nums){
            totalSum+=num;
        }
        if(totalSum%2 != 0) return false;
        vector<vector<int>> dp(n,vector<int>((totalSum/2)+1,-1));
        return recursion(n-1,totalSum/2,nums,dp);
    }
};