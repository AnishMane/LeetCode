class Solution {
public:
    
    bool safeCheck(int row, int col, vector<string>&board, int n){
        int tempRow = row;
        int tempCol = col;
        
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        col = tempCol;
        row = tempRow;
        
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = tempRow;
        col = tempCol;
        
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
    void combinations(int col, vector<string>&board , vector<vector<string>>& result, int n){
        if(col==n){
            result.push_back(board);
        }
        for(int row=0;row<n;row++){
            if(safeCheck(row,col,board,n)){
                board[row][col] = 'Q';
                combinations(col+1,board,result,n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        
        combinations(0,board,result,n);
        return result;
    }
};