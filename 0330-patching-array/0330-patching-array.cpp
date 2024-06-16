class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    int patches = 0;
    int i=0;
    long int x = 1;
    while(x<=n)
    {
        if(i<nums.size() && nums[i] <= x)
        {
            x+= nums[i];
            i++;
        }
        else{
            x*=2;
            patches+=1;
        }
    }
    return patches;
    }
};