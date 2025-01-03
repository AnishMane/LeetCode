class Solution {
public:
    
    int recursion(vector<int>& nums, int n, vector<int>& dp){
        if(n==0) return nums[0];
        if(n<1) return 0;
        if(dp[n]!=-1) return dp[n];
        
        int pick = nums[n] + recursion(nums,n-2,dp);
        int notPick = 0 + recursion(nums,n-1,dp);
        
        dp[n] = max(pick,notPick);
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        
        if(n==1)
            return nums[0];
        int leftLast = recursion(nums,n-2,dp1);
        vector<int> first(n-1);
        for(int i=1;i<n;++i){
            first[i-1] = nums[i];
        }
        int leftFirst = recursion(first,n-2,dp2);
        
        return max(leftFirst,leftLast);
    }
};