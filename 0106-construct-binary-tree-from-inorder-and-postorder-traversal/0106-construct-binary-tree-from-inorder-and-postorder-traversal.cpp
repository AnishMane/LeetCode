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
    TreeNode* dfs(vector<int>& inorder,vector<int>& postorder,unordered_map<int,int>& hashMap, int left, int right){
        if(left>right)
            return NULL;
        int rootVal = postorder.back();
        postorder.pop_back();
        int idx = hashMap[rootVal];
        TreeNode*root = new TreeNode(rootVal);
        root->right = dfs(inorder,postorder,hashMap,idx+1,right);
        root->left = dfs(inorder,postorder,hashMap,left,idx-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hashMap;
        for(int i=0;i<inorder.size();i++){
            hashMap[inorder[i]] = i;
        }
        return dfs(inorder,postorder,hashMap,0,postorder.size()-1);
    }
};