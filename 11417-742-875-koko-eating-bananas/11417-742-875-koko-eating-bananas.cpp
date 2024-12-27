class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r =0;
        for(int num:piles){
            r = max(r,num);
        }
        int result = r;
        
        while(l<=r){
            int mid = (l+r)/2;
            long long hours = 0;
            for(int p:piles){
                hours+=int(ceil((double)p/mid));
            }
            
            if(hours<=h){
                result = min(result,mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};