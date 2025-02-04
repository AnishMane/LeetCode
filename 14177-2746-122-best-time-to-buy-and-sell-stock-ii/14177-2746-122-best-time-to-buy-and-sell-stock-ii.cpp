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
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int nottake = dp[ind+1][1];
                    int take = dp[ind+1][0] - prices[ind];
                    dp[ind][buy] = max(nottake,take);
                }
                else{
                    int nottake = dp[ind+1][0];
                    int take = dp[ind+1][1] + prices[ind];

                    dp[ind][buy] = max(nottake,take);
                }
            }
        }
        
        return dp[0][1];
    }
};