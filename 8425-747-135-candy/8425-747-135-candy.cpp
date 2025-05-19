class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> result(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                result[i] = result[i-1] + 1;
            }
        }

        for(int i=n-1;i>0;i--){
            if(ratings[i-1] > ratings[i]){
                result[i-1] = max(result[i-1],result[i]+1);
            }
        }

        return accumulate(result.begin(),result.end(),0);
    }
};