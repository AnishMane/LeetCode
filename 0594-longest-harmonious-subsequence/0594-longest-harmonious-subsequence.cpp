class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int num:nums)
        {
            table[num]++;
        }
        int maxCount = 0;
        for(auto num : table)
        {
            if(table.find(num.first + 1) != table.end())
            {
                maxCount = max(maxCount, num.second + table[num.first+1]);
            }
        }
        return maxCount;

    }
};