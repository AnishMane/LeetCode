class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int,long long> hashMap;
        long long goodpairs = 0;
        for(int i=0;i<n;i++){
            goodpairs+= hashMap[nums[i]-i];
            hashMap[nums[i]-i]++;
        }
        long long totalpairs = n*(n-1)/2;
        return totalpairs-goodpairs;
    }
};