class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(),nums.end());
        int maxCount = 0;
        int count = 1;
        for(int i=1;i<nums.size();i++){
            while(nums[i] == nums[i-1]){
                i++;
                if(i==nums.size())
                    return max(maxCount,count);
            }
            if(nums[i] == nums[i-1] + 1){
                count++;
                maxCount = max(maxCount, count);
            }
            else{
                count = 1;
            }
        }
        return max(maxCount,count);
    }
};