class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum1 =0;
        for(int i=0;i<nums.size();i++)
        {
            sum1 += nums[i];
            int sum2 =0;
            for(int j =i+1;j<nums.size();j++)
            {
                sum2 = sum2 + nums[j];
            }
            if(sum1-nums[i] == sum2)
            {
                return i;
            }
        }
        return -1;
    }
};