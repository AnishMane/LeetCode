class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        hashMap[0] = -1;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(k!=0)
            {
                sum = sum %k;
            }
            
            if(hashMap.find(sum) != hashMap.end())
            {
                if(i - hashMap[sum] > 1)
                {
                    return true;
                }
                
            }else{
                    hashMap[sum] = i;
                }
        }
        return false;
    }
};