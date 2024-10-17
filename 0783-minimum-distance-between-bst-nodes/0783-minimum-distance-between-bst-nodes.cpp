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
    void difference(TreeNode* root, vector<int>& result){
        if(!root) return;
        result.push_back(root->val);
        difference(root->left,result);
        difference(root->right,result);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> result;
        difference(root,result);
        sort(result.begin(),result.end());
        int minDiff = INT_MAX;
        for(int i=0;i<result.size()-1;i++){
            minDiff = min(minDiff,result[i+1]-result[i]);
        }
        return minDiff;
    }
};