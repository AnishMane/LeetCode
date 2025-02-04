class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));

        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy==1){
                        int nottake = after[1][cap];
                        int take = -prices[ind] + after[0][cap];

                        cur[buy][cap] = max(nottake,take);
                    }
                    else{
                        int nottake = after[0][cap];
                        int take = prices[ind] + after[1][cap-1];

                        cur[buy][cap] = max(nottake,take);
                    }
                }
                after=cur;
            }
        }
        
        return after[1][2];
    }
};