class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
//         int smallest = INT_MAX;
//         int secondSmallest = INT_MAX;
//         int largest = INT_MIN;
//         int secondLargest = INT_MIN;

//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i] < smallest)
//             {
//                 secondSmallest = smallest;
//                 smallest = nums[i];
//             }
//             else if (nums[i] < secondSmallest)
//             {
//                 secondSmallest = nums[i];
//             }

//             if(nums[i] > largest)
//             {
//                 secondLargest = largest;
//                 largest = nums[i];
//             }
//             else if(nums[i] > secondLargest)
//             {
//                 secondLargest = nums[i];
//             }
//         }
//         int productDiff = (largest*secondLargest) - (smallest*secondSmallest);

//         return productDiff;
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1]*nums[nums.size()-2]) - (nums[0]*nums[1]);
    }
};