class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int allowed = candyType.size()/2;
        unordered_map<int,int> table;
        for(int num: candyType)
        {
            table[num]++;
        }
        int count = 0;
        for(auto num:table)
        {
            count++;
        }
        if(allowed <= count)
        {
            return allowed;
        }
       
            return count;
        
    }
};