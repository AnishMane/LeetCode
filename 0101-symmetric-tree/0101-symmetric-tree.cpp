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
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*> q;
        if(!root) return false;
        q.push(root);
        q.pop();
        if(root->left && root->right){
            q.push(root->left);
            q.push(root->right);
        }
        else if(!root->left && !root->right){
            return true;
        }
        else{
            return false;
        }
        while(!q.empty()){
            vector<int> temp1;
            vector<int> temp2;
            int qLen = q.size();
            if(qLen%2 != 0) return false;
            for(int i=0;i<qLen/2;i++){
                TreeNode* t = q.front();
                if(!t){
                    temp1.push_back(INT_MIN);
                    q.pop();
                    continue;
                } 
                else
                    temp1.push_back(t->val);
                q.pop();
                if(t->left)
                    q.push(t->left);
                else
                    q.push(NULL);
                if(t->right)
                    q.push(t->right);
                else
                    q.push(NULL);
            }
            for(int i=qLen/2;i<qLen;i++){
                TreeNode* t = q.front();
                if(!t){
                     temp2.push_back(INT_MIN);
                    q.pop();
                    continue;
                }
                else
                    temp2.push_back(t->val);
                q.pop();
                if(t->left)
                    q.push(t->left);
                else
                    q.push(NULL);
                if(t->right)
                    q.push(t->right);
                else
                    q.push(NULL);
            }
            reverse(temp2.begin(),temp2.end());
            if(temp1 != temp2) return false;
        }
        return true;

    }
};