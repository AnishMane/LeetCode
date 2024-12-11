class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowSet(9), colSet(9), blockSet(9);
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int n = board[i][j];
                if(n=='.') continue;
                
                int blockIndex = (i/3)*3 + (j/3);
                if(rowSet[i].count(n) || colSet[j].count(n) || blockSet[blockIndex].count(n))
                    return false;
                rowSet[i].insert(n);
                colSet[j].insert(n);
                blockSet[blockIndex].insert(n);
            }
        }
        return true;
    }
};