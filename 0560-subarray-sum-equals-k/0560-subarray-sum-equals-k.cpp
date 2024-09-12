class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        unordered_map<int,int> hashMap;
        hashMap[0]++;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(hashMap.find(sum-k)!= hashMap.end()){
                result+=hashMap[sum-k];
                hashMap[sum]++;
            }
            else{
                hashMap[sum]++;
            }
        }
        return result;
    }
};