class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int k=0;k<=amount;k++){
            if(k%coins[0]==0) dp[0][k] = k/coins[0];
            else dp[0][k] = 1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int nottake = dp[ind-1][target];
                int take = INT_MAX;
                if(target>=coins[ind]) take = 1 + dp[ind][target-coins[ind]];

                dp[ind][target] = min(take,nottake);
            }
        }
        
        int result = dp[n-1][amount];
        if(result>=1e9) return -1;
        return result;
    }
};