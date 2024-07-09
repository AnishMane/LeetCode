class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> check;
        vector<int> result;
        for(int i=0;i<nums2.size();i++)
        {
            check[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++)
        {
            int j = check[nums1[i]];
            bool temp = false;
            j++;
            while(j<nums2.size())
            {
                if(nums2[j] > nums1[i])
                {
                    
                    temp = true;
                    result.push_back(nums2[j]);
                    break;
                }
                j++;
            }
            if(!temp)
            {
                result.push_back(-1);
            }
        }
        return result;
    }
};