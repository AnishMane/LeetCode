class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        
        if(n==1)
            return nums[0];
        vector<int> first(n-1);
        for(int i=1;i<n;++i){
            first[i-1] = nums[i];
        }
        dp1[0] = nums[0];
        dp2[0] = first[0];
        int neg = 0;
        
        for(int i=1;i<n-1;++i){
            int pick = i>1 ? nums[i] + dp1[i-2] : nums[i] + 0;
            int notPick = 0 + dp1[i-1];
            
            dp1[i] = max(pick,notPick);
        }
        for(int i=1;i<n-1;++i){
            int pick = i>1 ? first[i] + dp2[i-2] : first[i] + 0;
            int notPick = 0 + dp2[i-1];
            
            dp2[i] = max(pick,notPick);
        }
        return max(dp2[n-2], dp1[n-2]);
    }
};