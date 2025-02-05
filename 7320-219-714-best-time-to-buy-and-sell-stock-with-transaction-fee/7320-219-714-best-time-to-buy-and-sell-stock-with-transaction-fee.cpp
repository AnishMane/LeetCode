class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2,0), cur(2,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int nottake = ahead[1];
                    int take = -prices[ind] + ahead[0];

                    cur[buy] = max(nottake,take);
                }
                else{
                    int nottake = ahead[0];
                    int take = prices[ind] + ahead[1] - fee;

                    cur[buy] = max(nottake,take);
                }
            }
            ahead = cur;
        }
        return ahead[1];
    }
};