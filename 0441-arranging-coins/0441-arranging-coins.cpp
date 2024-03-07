class Solution {
public:
    int arrangeCoins(int n) {
        int start = 1;
        int end = n;
        int res = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long coin = (long long)mid * (mid + 1) / 2;
            if (coin == n) {
                return mid;
            } else if (coin < n) {
                start = mid + 1;
                res = mid;
            } else {
                end = mid - 1;
            }
        }
        return res;
    }
};
