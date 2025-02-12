class Solution {
public:

    int digitSum(int n){
        int res = 0;
        while(n!=0){
            int temp = n%10;
            res+=temp;
            n = n/10;
        }
        return res;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        int maxi = -1;
        
        for(int num:nums){
            int dsum = digitSum(num);
            if(hashMap.find(dsum)!=hashMap.end()){
                maxi = max(maxi,hashMap[dsum]+num);
            }
            hashMap[dsum] = max(hashMap[dsum],num);
        }
        
        return maxi;
    }
};