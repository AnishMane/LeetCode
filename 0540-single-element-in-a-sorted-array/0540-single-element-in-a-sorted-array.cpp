class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        
        int mid = start + (end - start)/2;
        
        if (end == 0) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[end] != nums[end-1]) return nums[end];
        
        while(start <= end)
        {
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
            {
                return nums[mid];
            }
            
            if(nums[mid] == nums[mid+1] && mid%2 == 0 || nums[mid] == nums[mid-1] && mid%2 == 1)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }
};