/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        bool check = true;
        for(int i=0;i<grid.size() && check;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!= grid[0][0]){
                    check = false;
                    break;
                }
            }
        }
        if(!check){
            vector<vector<int>> grid1;
            vector<vector<int>> grid2;
            vector<vector<int>> grid3;
            vector<vector<int>> grid4;
            for(int i=0;i<grid.size()/2;i++){
                vector<int> temp1;
                for(int j=0;j<grid[i].size()/2;j++){
                    temp1.push_back(grid[i][j]);
                }
                grid1.push_back(temp1);
                vector<int> temp2;
                for(int j=grid[i].size()/2;j<grid[i].size();j++){
                    temp2.push_back(grid[i][j]);
                }
                grid2.push_back(temp2);
            }
            for(int i=grid.size()/2;i<grid.size();i++){
                vector<int> temp3;
                for(int j=0;j<grid[i].size()/2;j++){
                    temp3.push_back(grid[i][j]);
                }
                grid3.push_back(temp3);
                vector<int> temp4;
                for(int j=grid[i].size()/2;j<grid[i].size();j++){
                    temp4.push_back(grid[i][j]);
                }
                grid4.push_back(temp4);
            }
            Node* topLeft = construct(grid1);
            Node* topRight = construct(grid2);
            Node* bottomleft = construct(grid3);
            Node* bottomRight = construct(grid4);
            
            Node* result = new Node(true,false,topLeft,topRight,bottomleft,bottomRight);
            return result;
        }
        if(check){
            bool val;
            if(grid[0][0] == 0)
                val = false;
            if(grid[0][0] == 1)
                val = true;
            Node* result = new Node(val,true);
            return result;
        }
        return NULL;
    }
};