class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==1){
                        int nottake = dp[ind+1][1][cap];
                        int take = -prices[ind] + dp[ind+1][0][cap];

                        dp[ind][buy][cap] = max(nottake,take);
                    }
                    else{
                        int nottake = dp[ind+1][0][cap];
                        int take = prices[ind] + dp[ind+1][1][cap-1];

                        dp[ind][buy][cap] = max(nottake,take);
                    }
                }
            }
        }
        
        return dp[0][1][k];
    }
};