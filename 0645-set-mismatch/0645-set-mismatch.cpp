class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        unordered_set<int> hashSet;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(hashSet.find(nums[i])!= hashSet.end()){
                result[0] = nums[i];
            }
            else{
                hashSet.insert(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(hashSet.find(i+1)!=hashSet.end()){
                continue;
            }
            else{
                result[1] = i+1;
            }
        }
        return result;
    }
};