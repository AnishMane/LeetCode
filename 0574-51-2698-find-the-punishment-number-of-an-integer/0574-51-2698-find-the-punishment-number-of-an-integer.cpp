class Solution {
public:

    bool recursion(int n, string res, int target, int sum){
        if(n==0 && res=="") return sum==target;
        if(n==0) return false;

        int notpick = recursion(n/10,to_string(n%10)+res,target,sum);
        int pick = recursion(n/10,"",target,sum+stoi(to_string(n%10)+res));

        return pick || notpick;
    }

    int punishmentNumber(int n) {
        int total = 0;
        for(int i=1;i<=n;i++){
            if(recursion(i*i,"",i,0)) total+=i*i;
        }
        return total;
    }
};