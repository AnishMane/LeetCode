class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), cur(amount+1,0);
        
        for(int k=0;k<=amount;k++){
            if(k%coins[0]==0) prev[k] = k/coins[0];
            else prev[k] = 1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int nottake = prev[target];
                int take = INT_MAX;
                if(target>=coins[ind]) take = 1 + cur[target-coins[ind]];

                cur[target] = min(take,nottake);
            }
            prev = cur;
        }
        
        int result = prev[amount];
        if(result>=1e9) return -1;
        return result;
    }
};