class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int num:nums)
        {
            table[num]++;
        }
        int count = 0;
        int max = INT_MIN;
        for(auto num:table)
        {
            if(num.second > max)
            {
                max = num.second;
            }
        }
        for(auto num:table)
        {
            if(num.second == max)
            {
                count++;
            }
        }
        return count*max;
    }
};