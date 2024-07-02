class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>table1;
        unordered_map<int,int> table2;

        for(int num:nums1)
        {
            table1[num]++;
        }
        for(int num: nums2)
        {
            table2[num]++;
        }

        vector<int> result;
        for(int num: nums1)
        {
            if(table1.find(num) != table1.end() && table2.find(num) != table2.end())
            {
                result.push_back(num);
                table1[num]--;
                table2[num]--;
            }
            if(table1[num] == 0)
            {
                table1.erase(num);
            }
            if(table2[num] == 0)
            {
                table2.erase(num);
            }
        }
        return result;
    }
};