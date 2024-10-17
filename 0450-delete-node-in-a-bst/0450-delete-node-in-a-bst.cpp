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
    TreeNode* searchNode(TreeNode* root, int key)
    {
        if(!root) return NULL;
        if(root->val == key){
            if(!root->left&&root->right)
                root = root->right;
            else if(root->left&&!root->right)
                root = root->left;
            else if(!root->left&& !root->right){
                return NULL;
            }
                
            
            else{
                TreeNode* temp = root->left;
                root = root->right;
                TreeNode* cur = root;
                while(cur){
                    if(temp->val > cur->val){
                        if(!cur->right){
                            cur->right = temp;
                            break;
                        }
                        cur=cur->right;
                    }                
                    else{
                        if(!cur->left){
                            cur->left = temp;
                            break;
                        }
                        cur=cur->left;
                    }
                }
            }
        }
        if(root->left && key<root->val)
            root->left = searchNode(root->left,key);
        else if(root->right && key>root->val)
            root->right = searchNode(root->right,key);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        root = searchNode(root,key);
        return root;
    }
};