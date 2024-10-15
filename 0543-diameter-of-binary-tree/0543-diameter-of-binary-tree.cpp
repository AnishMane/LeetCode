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
    int ans = INT_MIN;
    int height(TreeNode* root){
        if(root!=NULL){
            int left = height(root->left);
            int right = height(root->right);
            ans = max(ans, left + right);
            return 1 + max(left,right);
        }
        else{
            return 0;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};