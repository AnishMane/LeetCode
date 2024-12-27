class Solution {
public:
    int findMin(vector<int>& nums) {
        int result;
        int maxNum = INT_MIN;
        for(int num:nums){
            maxNum = max(maxNum,num);
        }
        
        for(int i=0;i<nums.size();++i){
            if(nums[i] == maxNum){
                if(i==nums.size()-1)
                    return nums[0];
                else
                    return nums[i+1];
            }
        }
        return 0;
    }
};