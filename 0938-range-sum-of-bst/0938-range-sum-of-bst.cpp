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
    int result = 0;
    void calcSum(TreeNode* root, int low, int high){
        if(root){
            if(root->val >= low && root->val <= high){
                result+= root->val;
                calcSum(root->right,low,high);
                calcSum(root->left,low,high);
            }
            else if(root->val <= low)
                calcSum(root->right,low,high);
            else if(root->val >= high)
                calcSum(root->left,low,high);
        }
        return;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        calcSum(root,low,high);
        return result;
    }
};