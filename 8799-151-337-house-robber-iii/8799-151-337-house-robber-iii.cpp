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
    
    pair<int,int> recursion(TreeNode* root){
        if(!root) return {0,0};
        
        pair<int,int> leftPair = recursion(root->left);
        pair<int,int> rightPair = recursion(root->right);
        
        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first,leftPair.second) + max(rightPair.first,rightPair.second);
        
        return {withRoot,withoutRoot};
    }
    
    int rob(TreeNode* root) {
        pair<int,int> res = recursion(root);
        return max(res.first,res.second);
    }
};