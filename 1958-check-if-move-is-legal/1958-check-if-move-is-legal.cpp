class Solution {
public:
    
    bool legalCheck(int row, int col, char color, vector<vector<char>> board, int d[]){
        int dr = d[0];
        int dc = d[1];
        int nrow = row + dr;
        int ncol = col + dc;
        int length = 1;
        
        while(nrow>=0 && nrow<8 && ncol>=0 && ncol<8){
            length+=1;
            if(board[nrow][ncol] == '.') return false;
            if(board[nrow][ncol] == color){
                return length>=3;
            }
            nrow+=dr;
            ncol+=dc;
        }
        return false;
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int direction[8][2]  = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        board[rMove][cMove] = color;
        
        for(auto d: direction){
            if(legalCheck(rMove,cMove,color,board,d))
                return true;
        }
        return false;
    }
};