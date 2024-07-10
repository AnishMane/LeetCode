class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>> hashMap;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            hashMap[nums[i]].push_back(i);
        }
        for(auto num:hashMap)
        {
            sum += (num.second.size() * (num.second.size()-1))/2;
        }
        return sum;
    }
};