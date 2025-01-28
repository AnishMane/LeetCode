class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int k=0;k<=amount;k++){
            if(k%coins[0]==0) dp[0][k] = 1;
            else dp[0][k] = 0;
        }
        
        for(int ind=1;ind<n;++ind){
            for(int target=0;target<=amount;target++){
                long nottake = dp[ind-1][target];
                long take = 0;
                if(target>=coins[ind]) take = dp[ind][target-coins[ind]];

                dp[ind][target] = take + nottake;
            }
        }
        
        return dp[n-1][amount];
    }
};