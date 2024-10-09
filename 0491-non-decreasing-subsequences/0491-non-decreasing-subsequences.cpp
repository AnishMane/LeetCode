class Solution {
private:
    set<vector<int>> result;
public:
    void subsequence(int i, vector<int> nums, vector<int> res){
        if(i>= nums.size()){
            if(res.size() >= 2){
                for(int j=1;j<res.size();j++){
                    if(res[j]<res[j-1]){
                        return;
                    }
                }
                result.insert(res);
            }
            return;
        }
        res.push_back(nums[i]);
        subsequence(i+1,nums,res);
        res.pop_back();
        subsequence(i+1,nums,res);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> res;
        subsequence(0,nums,res);
        vector<vector<int>> answer;
        for(auto num:result){
            answer.push_back(num);
        }
        return answer;
    }
};