class Solution {
public:

    int recursion(int ind, int target, int n){
        if(target==0) return 1;
        if(ind>=n) return 0;

        int nottake = recursion(ind+1,target,n);
        int take = 0;
        if(target>=ind) take = ind * recursion(ind,target-ind,n);

        return max(nottake,take);
    }

    int integerBreak(int n) {
        return recursion(1,n,n);
    }
};