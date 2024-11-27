class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& heights, set<pair<int,int>>& hashSet, int delRow[], int delCol[]){
        vis[row][col] = 1;
        hashSet.insert({row,col});
        int n = heights.size();
        int m = heights[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(!vis[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]){
                    dfs(nrow,ncol,vis,heights,hashSet,delRow,delCol);
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> atlantic;
        set<pair<int,int>> pacific;
        
        vector<vector<int>> vis1(heights.size(), vector<int> (heights[0].size(),0));
        vector<vector<int>> vis2(heights.size(), vector<int> (heights[0].size(),0));
        
        int delRow[] = {0,-1,0,+1};
        int delCol[] = {-1,0,+1,0};
        
        int n = heights.size();
        int m = heights[0].size();
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(!vis1[i][j]){
                    if(j==m-1){
                        dfs(i,j,vis1,heights,atlantic,delRow,delCol);
                    }
                    else if(i==n-1){
                        dfs(i,j,vis1,heights,atlantic,delRow,delCol);
                    }
                }
            }
        }
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(!vis2[i][j]){
                    if(j==0){
                        dfs(i,j,vis2,heights,pacific,delRow,delCol);
                    }
                    else if(i==0){
                        dfs(i,j,vis2,heights,pacific,delRow,delCol);
                    }
                }
            }
        }
        vector<vector<int>> result;
        for(auto num:atlantic){
            if(pacific.count(num)){
                result.push_back({num.first,num.second});
            }
        }
        return result;
    }
};