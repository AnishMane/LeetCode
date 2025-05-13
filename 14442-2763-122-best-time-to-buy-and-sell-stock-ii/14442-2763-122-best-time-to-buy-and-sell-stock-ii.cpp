class Solution {
public:

    int recursion(int ind,int buy, vector<int> &prices, vector<vector<int>>&dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int take;
        int nottake;
        if(buy == 1){
            nottake = recursion(ind+1,buy,prices,dp);
            take = -prices[ind] + recursion(ind,0,prices,dp);
        }
        else{
            nottake = recursion(ind+1,buy,prices,dp);
            take = prices[ind] + recursion(ind+1,1,prices,dp);
        }
        return dp[ind][buy] = max(take,nottake);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return recursion(0,1,prices,dp);
    }
};