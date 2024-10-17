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
    
    void order(TreeNode* root,vector<vector<int>>& result, queue<TreeNode*>& q){
        if(!root) return;
        q.push(root);
        bool check = false;
        while(!q.empty()){
            int qLen = q.size();
            vector<int> temp;
            for(int i=0;i<qLen;i++){
                TreeNode* cur = q.front();
                temp.push_back(cur->val);
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(temp.empty()) continue;
            if(check){
                reverse(temp.begin(),temp.end());
                check = false;
            }
            else{
                check = true;
            }     
            result.push_back(temp);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        order(root,result,q);
        return result;
    }
};