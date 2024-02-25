class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int totalSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            totalSum += nums[i];
        }
        vector<int> temp;
        temp.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
        }
        temp.push_back(0);
        for(int i=1;i<temp.size()-1;i++)
        {
            sum = sum + temp[i-1];
            if(sum == (totalSum-sum-temp[i]))
            {
                return i-1;
            }
        }
        return -1;
    }
};