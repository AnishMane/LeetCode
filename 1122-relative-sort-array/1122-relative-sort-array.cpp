class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> hashMap;
        for(int num: arr1)
        {
            hashMap[num]++;
        }
        vector<int> result;
        for(int i=0;i<arr2.size();i++)
        {
                while(hashMap[arr2[i]] > 0)
                {
                    result.push_back(arr2[i]);
                    hashMap[arr2[i]]--;
                }
        }
        unordered_set<int>hashMap2;
        for(int num: arr2)
        {
            hashMap2.insert(num);
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr1.size();i++)
        {
            if(hashMap2.find(arr1[i])!= hashMap2.end())
            {
                
            }
            else{
                result.push_back(arr1[i]);
            }
        }
        return result;
    }
};