class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n);
        
        for(int j=0;j<n;++j){
            front[j] = triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;--i){
            vector<int> cur(n);
            for(int j=i;j>=0;--j){
                int sameI = triangle[i][j] + front[j];
                int nextI = triangle[i][j] + front[j+1];
                
               cur[j] = min(sameI,nextI);
            }
            front = cur;
        }
        
        return front[0];
    }
};