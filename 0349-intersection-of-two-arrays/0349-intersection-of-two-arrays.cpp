class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet;
        vector<int> result;
        for(int num:nums1){
            hashSet.insert(num);
        }
        for(int num:nums2){
            if(hashSet.find(num) != hashSet.end()){
                result.push_back(num);
                hashSet.erase(num);
            }
        }
        return result;
    }
};