class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int nottake = dp[ind+1][1];
                    int take = -prices[ind] + dp[ind+1][0];

                    dp[ind][buy] = max(nottake,take);
                }
                else{
                    int nottake = dp[ind+1][0];
                    int take = prices[ind] + dp[ind+2][1];

                    dp[ind][buy] = max(nottake,take);
                }
            }
        }
        
        return dp[0][1];
    }
};