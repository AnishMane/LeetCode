class Solution {
public:
    void swap(int&a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void permutations(int i, vector<int>&nums,vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permutations(i+1,nums,result);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutations(0,nums,result);
        return result;
    }
};