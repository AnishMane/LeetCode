class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashset;
        int n = nums.size();
        if(n<=1) return false;
        if(k>=n) k=n-1;
        for(int i=0;i<=k;i++){
            if(hashset.count(nums[i])) return true;
            hashset.insert(nums[i]);
        }
        
        int i=0;
        int j=k+1;
        while(j<n){
            hashset.erase(nums[i]);
            i++;
            if(hashset.count(nums[j])) return true;
            hashset.insert(nums[j]);
            j++;
        }
        return false;
    }
};