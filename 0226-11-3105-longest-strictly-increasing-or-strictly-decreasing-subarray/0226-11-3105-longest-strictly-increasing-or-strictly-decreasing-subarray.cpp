class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixI(n);
        vector<int> prefixD(n);
        
        prefixI[0] = prefixD[0] = 1;
        
        int maxi = 1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                prefixI[i] = prefixI[i-1] + 1;
                maxi = max(maxi,prefixI[i]);
            }
            else prefixI[i] = 1;
            
            if(nums[i-1]>nums[i]){
                prefixD[i] = prefixD[i-1] + 1;
                maxi = max(maxi,prefixD[i]);
            } 
            else prefixD[i] = 1;
        }
        
        return maxi;
    }
};