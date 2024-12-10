class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        
        int product = 1;
        for(int i=0;i<n;i++){
            leftProduct[i] = product * nums[i];
            product *= nums[i];
        }
        product = 1;
        for(int i=n-1;i>=0;i--){
            rightProduct[i] = product * nums[i];
            product*=nums[i];
        }
        vector<int> result(n);
        result[0] = rightProduct[1];
        result[n-1] = leftProduct[n-2];
        for(int i=1;i<n-1;i++){
            result[i] = leftProduct[i-1]*rightProduct[i+1];
        }
        return result;
    }
};