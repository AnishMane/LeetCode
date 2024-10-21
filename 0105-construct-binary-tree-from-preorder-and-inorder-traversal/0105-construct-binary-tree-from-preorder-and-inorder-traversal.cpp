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
    
    TreeNode* dfs(vector<int>& preorder, unordered_map<int,int>& hashMap,int left, int right){
        if(left>right)
            return NULL;
        int rootVal = preorder[0];
        preorder.erase(preorder.begin());
        int idx = hashMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->left = dfs(preorder,hashMap,left,idx-1);
        root->right = dfs(preorder,hashMap,idx+1,right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<inorder.size();i++){
            hashMap[inorder[i]] = i;
        }
        return dfs(preorder,hashMap,0,preorder.size()-1);
    }
};