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
    
    int indexOfArray(vector<int>& inorder, int val){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
    
    TreeNode* dfs(vector<int>& inorder,vector<int>& postorder, int left, int right){
        if(left>right)
            return NULL;
        int rootVal = postorder.back();
        postorder.pop_back();
        int idx = indexOfArray(inorder,rootVal);
        TreeNode*root = new TreeNode(rootVal);
        root->right = dfs(inorder,postorder,idx+1,right);
        root->left = dfs(inorder,postorder,left,idx-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder,postorder,0,postorder.size()-1);
    }
};