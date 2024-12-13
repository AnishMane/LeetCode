class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r= 1;
        int result = 0;
        
        while(r<n){
            if(prices[r]-prices[l] <= 0){
                l = r;
                r++;
            }
            else{
                result = max(result,prices[r]-prices[l]);
                r++;
            }
        }
        return result;
    }
};