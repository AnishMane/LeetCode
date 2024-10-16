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
    
    void insertion(TreeNode* root, int val){
        if(!root) return;
        if(val > root->val){
            if(!root->right){
                TreeNode* cur = new TreeNode(val);
                root->right = cur;
                return;
            }
            insertion(root->right,val);
        }
        if(val < root->val){
            if(!root->left){
                TreeNode* cur = new TreeNode(val);
                root->left = cur;
                return;
            }
            insertion(root->left,val);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* cur = new TreeNode(val);
            root = cur;
        }
        insertion(root,val);
        return root;
    }
};