class Solution {
public:
    
    int recursion(vector<int>& cost, int n, vector<int>& dp){
        if(n==0)return 0;
        if(dp[n]!=-1) return dp[n];
        int left = recursion(cost,n-1,dp) + cost[n];
        int right = INT_MAX;
        if(n > 1)
            right = recursion(cost,n-2,dp) + cost[n];
        dp[n] = min(left,right);
        return dp[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> costs(n+2);
        vector<int> dp(n+2,-1);
        dp[0] = 0;
        costs[0] = 0;
        costs[n+1] = 0;
        for(int i=1;i<n+1;++i){
            costs[i] = cost[i-1];
        }
        for(int i=1;i<n+2;++i){
            int first = dp[i-1] + costs[i];
            int second = INT_MAX;
            if(i>1)
                second = dp[i-2] + costs[i];
            dp[i] = min(first,second);
        }
        return dp[n+1];
    }
};