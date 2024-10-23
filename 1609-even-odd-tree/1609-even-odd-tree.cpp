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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int qLen = q.size();
            int prev1 = INT_MAX;
            int prev2 = INT_MIN;
            for(int i=0;i<qLen;i++){
                TreeNode* node = q.front();
                q.pop();
                if(level%2 != 0){
                    if(node->val%2 != 0 || prev1 <= node->val)
                        return false;
                    prev1 = node->val;
                }
                if(level%2 == 0){
                    if(node->val%2 == 0 || prev2 >= node->val)
                        return false;
                    prev2 = node->val;
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};