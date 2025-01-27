/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int goodNums = 0;
public:
    
    void checkNodes(TreeNode* root, int maxNum){
        if(!root) return;
        if(root->val >= maxNum){
            maxNum = root->val;
            goodNums++;
        }
        checkNodes(root->left,maxNum);
        checkNodes(root->right,maxNum);
    }
    
    int goodNodes(TreeNode* root) {
        checkNodes(root,INT_MIN);
        return goodNums;
    }
};