class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n == 0){
            return 1;
        }
        
        if(n<0){
            x = 1/x;
            N= -N;
        }
        
        if(n%2 == 0){
            double half = myPow(x,N/2);
            return half*half;
        }
            return x*myPow(x,N-1);
    }
};