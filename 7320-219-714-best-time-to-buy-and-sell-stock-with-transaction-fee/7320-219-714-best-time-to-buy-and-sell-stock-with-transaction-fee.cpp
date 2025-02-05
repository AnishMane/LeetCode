class Solution {
public:

    int recursion(int ind, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1){
            int nottake = recursion(ind+1,1,fee,prices,dp);
            int take = -prices[ind] + recursion(ind+1,0,fee,prices,dp);

            return dp[ind][buy] = max(nottake,take);
        }
        else{
            int nottake = recursion(ind+1,0,fee,prices,dp);
            int take = prices[ind] + recursion(ind+1,1,fee,prices,dp) - fee;

            return dp[ind][buy] = max(nottake,take);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recursion(0,1,fee,prices,dp);
    }
};