class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int num:nums)
        {
            table[num]++;
        }
        int i =0;
        while(i<nums.size())
        {
            if(table.find(i) != table.end())
            {
                i++;
                continue;
            }
            else{
                return i;
            }
        }
        return i;
    }
};