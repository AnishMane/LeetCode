class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int calc = start^goal;
        
        while(calc!=0){
            count += calc & 1;
            calc >>= 1;
        }
        return count;
    }
};