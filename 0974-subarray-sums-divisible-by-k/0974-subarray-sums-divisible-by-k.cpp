class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        hashMap[0] =1;
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int remainder = sum%k;
            if(remainder <0){
                remainder += k;
            }
            
            if(hashMap.find(remainder) != hashMap.end()){
                count += hashMap[remainder];
            }
            hashMap[remainder]++;
        }
        return count;
    }
};