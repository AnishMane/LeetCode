class Solution {
public:
    
    bool recursion(int i,int j, vector<vector<char>>& board, string word, int index, int delRow[], int delCol[]){
        int m = board.size();
        int n = board[0].size();
        if(index==word.size()) return true;
        if(i<0 || j<0 || i>=m || j>=n) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';  // Mark as visited
        
        for (int it = 0; it < 4; ++it) {
            int nrow = i + delRow[it];
            int ncol = j + delCol[it];

            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && board[nrow][ncol] == word[index]) {
                if (recursion(nrow, ncol, board, word, index + 1, delRow, delCol)) {
                    board[i][j] = temp;
                    return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0) return false;
        
        int delRow[] = {0,1,0,-1};
        int delCol[] = {1,0,-1,0};
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]==word[0] && recursion(i,j,board,word,1,delRow,delCol)){
                    return true;
                }
            }
        }
        return false;
    }
};