class Solution {
public:
    unordered_set<int> table;
    bool isHappy(int n) {
        int sum = 0;
        while(n != 0)
        {
            sum = sum + (n%10)*(n%10);
            n = n/10;
        }
        
        
        if(sum == 1)
        {
            return true;
        }
        
        if(table.find(sum) != table.end())
        {
            return false;
        }
        
        table.insert(sum);
        return isHappy(sum);
        
        
    }
};