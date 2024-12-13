class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxRight(n);
        maxRight[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxRight[i] = max(maxRight[i+1],prices[i+1]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            result = max(result,maxRight[i]-prices[i]);
        }
        return result;
    }
};