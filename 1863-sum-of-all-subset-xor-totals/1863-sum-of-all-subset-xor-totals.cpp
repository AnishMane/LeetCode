class Solution {
private:
    int sum = 0;
public:
    
    void XORSum(int i, vector<int>&nums, vector<int>& subset){
        if(i==nums.size()){
            if(subset.empty()){
                return;
            }
            int xOR = subset[0];
            for(int j=1;j<subset.size();j++){
                xOR ^= subset[j];
            }
            sum+=xOR;
            return;
        }
        subset.push_back(nums[i]);
        XORSum(i+1,nums,subset);
        subset.pop_back();
        XORSum(i+1,nums,subset);
    }
    
    int subsetXORSum(vector<int>& nums) {
        vector<int> subset;
        XORSum(0,nums,subset);
        return sum;
    }
};