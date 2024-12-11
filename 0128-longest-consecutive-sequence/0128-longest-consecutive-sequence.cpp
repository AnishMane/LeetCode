class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        int maxCount = 0;
        int curr = 0;
        
        for(int num:nums){
            hashSet.insert(num);
        }
        
        for(int i=0;i<nums.size();i++){
            curr = nums[i];
            int count = 1;
            if(hashSet.find(nums[i]-1) == hashSet.end()){
                while(hashSet.find(curr+1)!=hashSet.end()){
                    count++;
                    curr++;
                }
                maxCount = max(maxCount,count);
            }
        }
        return maxCount;
    }
};