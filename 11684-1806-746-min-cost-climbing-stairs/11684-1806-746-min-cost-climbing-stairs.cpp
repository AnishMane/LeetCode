class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = 0;
        int prev2 = 0;
        
        for(int i=0;i<n;++i){
            int temp = cost[i] + min(prev,prev2);
            prev2 = prev;
            prev = temp;
        }
        return min(prev,prev2);
    }
};