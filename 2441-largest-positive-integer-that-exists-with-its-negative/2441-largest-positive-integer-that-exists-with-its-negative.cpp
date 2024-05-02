class Solution {
public:
    int findMaxK(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i] > nums[j])
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j <nums.size();j++)
            {
                if((nums[j] == nums[i]*(-1)))
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};