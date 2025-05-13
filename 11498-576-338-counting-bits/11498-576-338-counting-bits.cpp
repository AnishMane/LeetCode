class Solution {
public:

    int checker(int n){
        int res = 0;
        while(n>0){
            res+=(n%2);
            n/=2;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++){
            result.push_back(checker(i));
        }
        return result;
    }
};