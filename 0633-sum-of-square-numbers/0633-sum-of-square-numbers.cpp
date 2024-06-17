class Solution {
public:
    bool isPerfectSquare(long long n)
    {
        long long sqrtN = static_cast<long long>(sqrt(n));
        return sqrtN*sqrtN == n;
    }
    
    bool judgeSquareSum(int c) {
        for(long long a=0; a*a <=c; a++)
        {
            long long b = c - a*a;
            
            if(isPerfectSquare(b))
            {
                return true;
            }
        }
        return false;
    }
};