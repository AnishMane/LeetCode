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
public:
    bool evaluateTree(TreeNode* root) {
        if(!root)return false;
        if(!root->left&&!root->right){
            return root->val==0 ? false : true;
        }
        return root->val==2 ? evaluateTree(root->left)|evaluateTree(root->right) : evaluateTree(root->left)&evaluateTree(root->right);
    }
};