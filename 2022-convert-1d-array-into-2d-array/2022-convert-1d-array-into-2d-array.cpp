class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(m*n == 1 && size!=1){
            return {};
        }
        if(size%(m*n) != 0 ){
            return {};
        }
        // else if(n==1){
        //     if(m!= original.size()){
        //         return {};
        //     }
        // }else if(m == 1){
        //     if(n!= original.size()){
        //         return {};
        //     }
        // }
        
        vector<vector<int>> result;
        vector<int> temp;
        int count = 0;
        int mcount = 0;
        for(int i=0;i<original.size();i++){
            if(mcount>m){
                return {};
            }
            temp.push_back(original[i]);
            count++;
            if(count == n){
                result.push_back(temp);
                count = 0;
                mcount++;
                temp.clear();
            }
        }
        return result;
        
    }
};