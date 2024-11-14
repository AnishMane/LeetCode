class Solution {
public:
    
    void helper(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> vis){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int initial = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        int n = image.size();
        int m = image[0].size();
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    if(delcol == 0 || delrow == 0){
                        int nrow = i + delrow;
                        int ncol = j + delcol;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                            if(image[nrow][ncol] == initial && !vis[nrow][ncol]){
                                image[nrow][ncol] = color;
                                vis[nrow][ncol] = 1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(), 0));
        helper(image,sr,sc,color,vis);
        return image;
    }
};