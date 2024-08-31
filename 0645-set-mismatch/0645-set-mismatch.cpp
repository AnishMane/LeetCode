class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long sum =0,squareSum = 0;
        long long expectedSum = n*(n+1)/2;
        long long expectedSquareSum = (long long)n*(n+1)*(2*n+1)/6;
        
        for(int num:nums){
            sum += num;
            squareSum += (long long) num*num;
        }
        
        long long diffSum = sum - expectedSum;
        long long diffSquareSum = squareSum - expectedSquareSum;
        
        long long sumOfNums = diffSquareSum/diffSum;
        
        int duplicate = (diffSum + sumOfNums)/2;
        int missing = sumOfNums - duplicate;
        return {duplicate,missing};
    }
};