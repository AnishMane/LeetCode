class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_set<string> result;
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i] == num[i+1] && num[i]== num[i+2])
            {
                result.insert(string(1,num[i]) + string(1,num[i+1]) + string(1,num[i+2]));
            }
        }
        string max = "";
        for(auto n:result)
        {
            if(n > max)
            {
                max = n;
            }
        }
        return max;
    }
};