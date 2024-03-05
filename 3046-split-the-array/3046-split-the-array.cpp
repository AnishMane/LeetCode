class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> table;
        
        for(int num:nums)
        {
            table[num]++;
        }
        for(auto num:table)
        {
            if(num.second > 2)
            {
                return false;
            }
        }
        return true;
    }
};