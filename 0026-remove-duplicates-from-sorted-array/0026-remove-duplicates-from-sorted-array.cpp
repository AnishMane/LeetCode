class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int i=0;i<nums.size();i++)
        {
            table[nums[i]]++;
            if(table[nums[i]] > 1)
            {
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin(),nums.end());
        int count = 0;
        for(auto num:table)
        {
            count++;
        }
        return count;
    }
};