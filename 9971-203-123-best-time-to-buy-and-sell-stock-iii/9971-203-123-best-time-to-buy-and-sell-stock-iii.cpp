class Solution {
public:

    int recursion(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        if(buy==1){
            int nottake = recursion(ind+1,1,cap,prices,dp);
            int take = -prices[ind] + recursion(ind+1,0,cap,prices,dp);

            return dp[ind][buy][cap] = max(nottake,take);
        }
        else{
            int nottake = recursion(ind+1,0,cap,prices,dp);
            int take = prices[ind] + recursion(ind+1,1,cap-1,prices,dp);

            return dp[ind][buy][cap] = max(nottake,take);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return recursion(0,1,2,prices,dp);
    }
};