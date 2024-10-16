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
    string result = "";
public:
    void tree(TreeNode*root){
        if(!root){
            return;
        }
        if(root->left && !root->right){
            result+= to_string(root->val);
            result+="(";
            tree(root->left);
            result+=")";
        }
        if(!root->left && root->right){
            result+= to_string(root->val);
            result+="()(";
            tree(root->right);
            result+= ")";
        }
        if(!root->left && !root->right){
            result+= to_string(root->val);
            return;
        }
        if(root->left && root->right){
            result+= to_string(root->val);
            result+= "(";
            tree(root->left);
            result+= ")(";
            tree(root->right);
            result+= ")";
        }
        return;
    }
    
    string tree2str(TreeNode* root) {
        tree(root);
        return result;
    }
};