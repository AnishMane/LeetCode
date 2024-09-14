class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = INT_MIN;
        for(int num:nums){
            if(num > max){
                max = num;
            }
        }
        int maxCount = 0;
        int count = 0;
        for(int num:nums){
            if(num == max){
                count++;
                if(maxCount < count){
                    maxCount = count;
                }
            }
            else{
                count = 0;
            }
        }
        return maxCount;
    }
};