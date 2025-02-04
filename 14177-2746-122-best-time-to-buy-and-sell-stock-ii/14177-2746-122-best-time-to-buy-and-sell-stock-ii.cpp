class Solution {
public:

    int recursion(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1){
            int nottake = recursion(ind+1,1,prices,dp);
            int take = recursion(ind+1,0,prices,dp) - prices[ind];
            return dp[ind][buy] = max(nottake,take);
        }
        else{
            int nottake = recursion(ind+1,0,prices,dp);
            int take = recursion(ind+1,1,prices,dp) + prices[ind];

            return dp[ind][buy] = max(nottake,take);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recursion(0,1,prices,dp);
    }
};