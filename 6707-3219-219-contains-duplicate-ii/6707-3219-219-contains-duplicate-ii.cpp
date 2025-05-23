class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int l = 0;
        int n = nums.size();
        
        for(int r=0;r<n;r++){
            if(r-l>k){
                window.erase(nums[l]);
                l++;
            }
            if(window.count(nums[r])) return true;
            window.insert(nums[r]);
        }
        return false;
    }
};