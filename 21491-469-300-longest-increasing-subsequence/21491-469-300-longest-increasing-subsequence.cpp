class Solution {
public:

    int recursion(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int nottake = recursion(ind+1,prev,nums,dp);
        int take = 0;
        if(prev==-1 || nums[prev]<nums[ind]) take = 1 + recursion(ind+1,ind,nums,dp);

        return dp[ind][prev+1] = max(nottake,take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return recursion(0,-1,nums,dp);
    }
};