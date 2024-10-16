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
    bool checkPath(TreeNode* root, int curSum, int targetSum){
        if(!root) return false;
        curSum += root->val;
        if(!root->left && !root->right){
            return curSum == targetSum;
        }
        return checkPath(root->left,curSum,targetSum) || checkPath(root->right,curSum,targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkPath(root,0,targetSum);
    }
};