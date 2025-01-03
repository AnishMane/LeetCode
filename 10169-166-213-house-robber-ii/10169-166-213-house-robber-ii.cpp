class Solution {
public:
    
//     int maximumNonAdjacentSum(vector<int>& nums){
//         int n = nums.size();
        
//         int prev = 
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        vector<int> first(n-1);
        for(int i=1;i<n;++i){
            first[i-1] = nums[i];
        }
        int prevA = nums[0];
        int prevB = first[0];
        int prevA2 = 0;
        int prevB2 = 0;
        
        for(int i=1;i<n-1;++i){
            int pick = nums[i] + prevA2;
            int notPick = 0 + prevA;
            
            int temp = max(pick,notPick);
            prevA2 = prevA;
            prevA = temp;
        }
        for(int i=1;i<n-1;++i){
            int pick = first[i] + prevB2;
            int notPick = 0 + prevB;
            
            int temp = max(pick,notPick);
            prevB2 = prevB;
            prevB = temp;
        }
        return max(prevA,prevB);
    }
};