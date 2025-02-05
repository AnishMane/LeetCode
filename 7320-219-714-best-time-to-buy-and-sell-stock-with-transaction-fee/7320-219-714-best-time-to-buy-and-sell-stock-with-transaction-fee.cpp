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
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int nottake = dp[ind+1][1];
                    int take = -prices[ind] + dp[ind+1][0];

                    dp[ind][buy] = max(nottake,take);
                }
                else{
                    int nottake = dp[ind+1][0];
                    int take = prices[ind] + dp[ind+1][1] - fee;

                    dp[ind][buy] = max(nottake,take);
                }
            }
        }
        return dp[0][1];
    }
};