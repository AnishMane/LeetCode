class Solution {
public:
    
    bool recursion(vector<vector<int>>& matrix, int l,int r,int m,int n, int target){
        if(l>r)
            return false;
        int mid = (l+r)/2;
        
        if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
            for(int i=0;i<n;++i){
                if(target == matrix[mid][i])
                    return true;
            }
        }
        else if(target>matrix[mid][n-1])
            return recursion(matrix,mid+1,r,m,n,target);
        else
            return recursion(matrix,l,mid-1,m,n,target);
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        return recursion(matrix,0,m-1,m,n,target);
    }
};