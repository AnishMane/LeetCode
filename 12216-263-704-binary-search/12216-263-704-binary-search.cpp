class Solution {
public:
    
    int recursion(vector<int>&nums,int l,int r, int target){
        if(l>r)
            return -1;
        
        int mid = (l+r)/2;
        if(nums[mid] == target)
            return mid;
        else if(target>nums[mid])
            return recursion(nums,mid+1,r,target);
        else
            return recursion(nums,l,mid-1,target);
    }
    
    int search(vector<int>& nums, int target) {
        return recursion(nums,0,nums.size()-1,target);
    }
};