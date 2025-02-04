class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0), cur(2,0);
        ahead[0] = ahead[1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int nottake = ahead[1];
                    int take = ahead[0] - prices[ind];
                    cur[buy] = max(nottake,take);
                }
                else{
                    int nottake = ahead[0];
                    int take = ahead[1] + prices[ind];

                    cur[buy] = max(nottake,take);
                }
            }
            ahead = cur;
        }
        
        return ahead[1];
    }
};