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

    // root of the tree and i need to remove all the nodes which are leaf nodes and have value as target


    TreeNode* recursion(TreeNode* root, int target){
        if(!root) return nullptr;
        root->left = recursion(root->left,target);
        root->right = recursion(root->right,target);

        if(!root->left && !root->right && root->val == target) return nullptr;
        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return recursion(root,target);
    }
};