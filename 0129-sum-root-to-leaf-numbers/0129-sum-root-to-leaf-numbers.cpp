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
private:
    int totalSum = 0;
public:
    
    void calcSum(TreeNode* root,string s){
        if(!root) return;
        if(!root->left && !root->right){
            s+=to_string(root->val);
            totalSum += stoi(s);
        }
        s += to_string(root->val);
        calcSum(root->left,s);
        calcSum(root->right,s);
    }
    
    int sumNumbers(TreeNode* root) {
        string s = "";
        calcSum(root,s);
        return totalSum;
    }
};