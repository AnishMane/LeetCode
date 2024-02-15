class Solution {
public:
    int fibo(int n, vector<int>&dp)
    {
        if(n<= 1)
        {
            return n;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
        return dp[n];
    }
    
    int fib(int n) {
        vector<int> dp(n+1,-1);
        // for(int i =0;i<=n;i++){
        //     dp[i] = -1;
        // }
        int sum = fibo(n,dp);
        return sum;
    }
};