class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> table;
        for(int i=0;i<nums.size();i++)
        {
            table[nums[i]]++;
            if(table[nums[i]] > 2)
            {
                nums[i] = INT_MAX;
            }
        }
        sort(nums.begin(),nums.end());
        int count = 0;
        int i =0;
        while(i < nums.size())
        {
            if(nums[i] != INT_MAX){
                count++;
            }
            
            i++;
        }
        return count;
    }
};