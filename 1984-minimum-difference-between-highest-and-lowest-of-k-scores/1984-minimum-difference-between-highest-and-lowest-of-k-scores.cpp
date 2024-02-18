class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-k;
        int j = nums.size()-1;
        int min = INT_MAX;
        if(nums.size() == 1)
        {
            return 0;
        }
        while(i>=0)
        {
            if(min > nums[j]-nums[i])
            {
                min = nums[j] - nums[i];
            }
            i--;
            j--;
        }
        return min;
    }
};