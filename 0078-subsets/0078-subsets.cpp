class Solution {
private:
    set<vector<int>> hashSet;
public:
    void sub(int i, vector<int>& nums, vector<int>& res){
        if(i==nums.size()){
            hashSet.insert(res);
            return;
        }
        res.push_back(nums[i]);
        sub(i+1,nums,res);
        res.pop_back();
        sub(i+1,nums,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        sub(0,nums,res);
        vector<vector<int>> result;
        for(auto num:hashSet){
            result.push_back(num);
        }
        return result;
    }
};