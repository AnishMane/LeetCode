class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1,0), cur(amount+1,0);
        
        
        for(int k=0;k<=amount;k++){
            if(k%coins[0]==0) prev[k] = 1;
            else prev[k] = 0;
        }
        
        for(int ind=1;ind<n;++ind){
            for(int target=0;target<=amount;target++){
                long nottake = prev[target];
                long take = 0;
                if(target>=coins[ind]) take = cur[target-coins[ind]];

                cur[target] = take + nottake;
            }
            prev = cur;
        }
        
        return prev[amount];
    }
};