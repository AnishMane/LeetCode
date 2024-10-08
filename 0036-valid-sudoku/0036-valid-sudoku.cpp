class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i){
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            for(int j=0;j<9;++j){
                if(board[i][j] != '.'){
                    if(rowSet.count(board[i][j])){
                        return false;
                    }
                    rowSet.insert(board[i][j]);
                }
                if(board[j][i] != '.'){
                    if(colSet.count(board[j][i])){
                        return false;
                    }
                    colSet.insert(board[j][i]);
                }
            }
        }
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<char> boxSet;
                for(int a=0;a<3;++a){
                    for(int b=0;b<3;++b){
                        if(board[i+a][j+b] != '.')
                        {
                            if(boxSet.count(board[i+a][j+b])){
                                return false;
                            }
                            boxSet.insert(board[i+a][j+b]);
                        }
                        
                    }
                }
            }
        }
        return true;
    }
};