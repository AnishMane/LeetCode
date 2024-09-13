class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for(int i=0;i<queries.size();++i){
            int sum = arr[queries[i][0]];
            if(queries[i][0] == queries[i][1]){
                result.push_back(sum);
                continue;
            }
            int left = queries[i][0]+1;
            int right = queries[i][1];
            while(left <= right){
                sum = sum ^ arr[left];
                left++;
            }
            result.push_back(sum);
        }
        return result;
    }
};