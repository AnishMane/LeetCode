class Solution {
public:
    
    int recursion(int ind, int target, vector<int> &nums){
        
        if(ind==0){
            if (target == nums[0] && nums[0] == 0) return 2;
            if(target == nums[0] || target == -nums[0]) return 1;
            return 0;
        }
        
        int minus = recursion(ind-1,target+nums[ind],nums);
        int plus = recursion(ind-1,target-nums[ind],nums);
        
        return minus+plus;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        return recursion(n-1,target,nums);
    }
};