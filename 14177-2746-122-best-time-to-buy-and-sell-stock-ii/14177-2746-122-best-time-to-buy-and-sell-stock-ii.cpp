class Solution {
public:
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