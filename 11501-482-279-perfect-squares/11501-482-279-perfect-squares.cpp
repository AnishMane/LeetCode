class Solution {
private:
    unordered_map<int,int> dp;
    
public:
    int recursion(int ind, int target,int n){
        if(dp.count(target)) return dp[target];
        if(ind*ind>target) return 1e9;

        int nottake = recursion(ind+1,target,n);
        int take = 1e9;
        if(target>=ind*ind) take = 1 + recursion(ind,target-ind*ind,n);

        return dp[target] = min(nottake,take);
    }

    int numSquares(int n) {
        if(n==1 || n==0) return n;
        dp[0] = 0;
        return recursion(1,n,n);
    }
};