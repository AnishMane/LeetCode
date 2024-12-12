class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> hashSet;
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    hashSet.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        for(auto it:hashSet){
            result.push_back(it);
        }
        return result;
    }
};