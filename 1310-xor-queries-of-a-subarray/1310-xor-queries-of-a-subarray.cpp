class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix_xor(n);
        vector<int> result(queries.size());
        
        prefix_xor[0] = arr[0];
        for(int i=1;i<n;++i){
            prefix_xor[i] = prefix_xor[i-1] ^ arr[i];
        }
        
        for(int i=0;i<queries.size();++i){
            int left = queries[i][0];
            int right = queries[i][1];
            
            if(left == 0){
                result[i] = prefix_xor[right];
            }
            else{
                result[i] = prefix_xor[left-1] ^ prefix_xor[right];
            }
        }
        return result;
    }
};