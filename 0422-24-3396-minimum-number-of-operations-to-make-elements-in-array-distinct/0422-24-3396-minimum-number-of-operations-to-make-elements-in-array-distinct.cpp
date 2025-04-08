class Solution {
public:

    bool checkDuplicate(unordered_map<int,int>&hashmap){
        for(auto it:hashmap){
            if(it.second>1) return false;
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> hashmap;
        for(int num:nums) hashmap[num]++;
        int count = 0;
        if(nums.size()<3){
            if(checkDuplicate(hashmap)) return 0;
            return 1;
        }
        for(int i=0;i<=nums.size()-3;i+=3){
            if(checkDuplicate(hashmap)) return count;
            hashmap[nums[i]]--;
            hashmap[nums[i+1]]--;
            hashmap[nums[i+2]]--;
            count++;
        }
        if(checkDuplicate(hashmap)) return count;
        return count+1;
    }
};