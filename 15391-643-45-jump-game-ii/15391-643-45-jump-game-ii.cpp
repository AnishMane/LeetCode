class Solution {
public:
    
    int recursion(int i, vector<int>&nums, vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int mini = 1e9;
        
        for(int j=1;j<=nums[i];j++){
            mini = min(mini,1 + recursion(i+j,nums,dp));
        }
        return dp[i] = mini;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return recursion(0,nums,dp);
    }
};