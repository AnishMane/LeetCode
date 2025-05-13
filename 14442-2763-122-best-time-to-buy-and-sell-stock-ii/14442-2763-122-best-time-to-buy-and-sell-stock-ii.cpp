class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int take;
                int nottake;
                if(buy == 1){
                    nottake = dp[ind+1][buy];
                    take = -prices[ind] + dp[ind][0];
                }
                else{
                    nottake = dp[ind+1][buy];
                    take = prices[ind] + dp[ind+1][1];
                }
                dp[ind][buy] = max(take,nottake);
            }
        }
        
        return dp[0][1];
    }
};