class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> table;
        for(int i=0;i<nums.size();i++)
        {
            table[nums[i]]++;
        }
        for(auto num:table)
        {
            if(num.second == 1)
            {
                return num.first;
            }
        }
        return 0;
    }
};