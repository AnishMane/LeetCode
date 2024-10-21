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
    
    bool checkValid(TreeNode*root, long long minimum, long long maximum){
        if(!root) return true;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(root->val <= minimum || root->val >= maximum)
            return false;
        bool checkLeft = checkValid(root->left,minimum,root->val);
        bool checkRight = checkValid(root->right,root->val,maximum);
        return checkLeft && checkRight;
    }
    
    bool isValidBST(TreeNode* root) {
        return checkValid(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
    }
};