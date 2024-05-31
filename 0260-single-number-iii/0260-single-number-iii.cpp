class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> checker;
        for(int num:nums)
        {
            checker[num]++;
        }
        
        for(auto num:checker)
        {
            if(num.second == 1)
            {
                result.push_back(num.first);
            }
        }
        return result;
        
    }
};