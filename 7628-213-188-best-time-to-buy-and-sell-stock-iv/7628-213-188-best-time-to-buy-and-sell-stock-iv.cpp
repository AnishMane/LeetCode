class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));

        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==1){
                        int nottake = ahead[1][cap];
                        int take = -prices[ind] + ahead[0][cap];

                        cur[buy][cap] = max(nottake,take);
                    }
                    else{
                        int nottake = ahead[0][cap];
                        int take = prices[ind] + ahead[1][cap-1];

                        cur[buy][cap] = max(nottake,take);
                    }
                }
                ahead=cur;
            }
        }
        
        return ahead[1][k];
    }
};