class Solution {
public:

    int recursion(int l, int r, vector<int>& nums, int target){
        if(l>r) return -1;

        int mid = l + (r-l)/2;

        if(nums[mid] == target) return mid;

        if(nums[l]<=nums[mid]){
            if(nums[l]<=target && target<nums[mid]){
                return recursion(l,mid-1,nums,target);
            }
            else{
                return recursion(mid+1,r,nums,target);
            }
        }
        else{
            if(nums[mid]<target && target<=nums[r]){
                return recursion(mid+1,r,nums,target);
            }
            else{
                return recursion(l,mid-1,nums,target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return recursion(0,nums.size()-1,nums,target);
    }
};