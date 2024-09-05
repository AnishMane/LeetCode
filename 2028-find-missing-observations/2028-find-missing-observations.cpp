class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumRolls = 0;
        for(int num:rolls){
            sumRolls+=num;
        }
        int sumOfNew = (mean)*(rolls.size() + n) - sumRolls;
        
        if(n*6 < sumOfNew || n > sumOfNew){
            return {};
        }
        
        int rem = sumOfNew%n;
        int quo = sumOfNew/n;
        
        vector<int> result(n,quo);
        for(int i=0;i<rem;i++){
            result[i]++;
        }
        return result;
    }
};