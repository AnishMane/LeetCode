class Solution {
public:
    string convertDtoB(int n){
        string res = "";
        while(n!=1){
            if(n%2 == 1){
                res+='1';
            }
            else{
                res+='0';
            }
            n = n/2;
        }
        res+= '1';
        reverse(res.begin(),res.end());
        return res;
    }
    
    int minBitFlips(int start, int goal) {
        int calc = start ^ goal;
        if(calc == 0){
            return 0;
        }
        string cal = convertDtoB(calc);
        int result = 0;
        for(int i=0;i<cal.size();++i){
            if(cal[i] == '1'){
                result++;
            }
        }
        return result;
    }
};