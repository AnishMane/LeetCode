class Solution {
public:
    
    int recursion(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[0]==0) return target/coins[0];
            return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int nottake = recursion(ind-1,target,coins,dp);
        int take = INT_MAX;
        if(target>=coins[ind]) take = 1 + recursion(ind,target-coins[ind],coins,dp);
        
        return dp[ind][target] = min(take,nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int result = recursion(n-1,amount,coins,dp);
        if(result>=1e9) return -1;
        return result;
    }
};