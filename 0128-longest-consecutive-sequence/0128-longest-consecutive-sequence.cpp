class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int num:nums){
            hashSet.insert(num);
        }
        int maxCount = 0;
        
        for(int i=0;i<nums.size();i++){
            int count = 0;
            int n = nums[i];
            if(!hashSet.count(n))
                continue;
            while(hashSet.count(n)){
                n--;
            }
            n++;
            while(hashSet.count(n)){
                hashSet.erase(n);
                count++;
                n++;
                maxCount = max(maxCount,count);
            }
        }
        return maxCount;
    }
};