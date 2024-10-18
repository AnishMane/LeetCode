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
    unordered_map<string,int> hashMap;
    vector<TreeNode*> result;
public:
    string serialize(TreeNode* root){
        if(!root) return "#";
        string ser = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        hashMap[ser]++;
        if(hashMap[ser] == 2)
            result.push_back(root);
        return ser;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};