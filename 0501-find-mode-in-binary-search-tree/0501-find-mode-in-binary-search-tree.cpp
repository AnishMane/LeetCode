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
    unordered_map<int,int> hashMap;
public:
    
    void dfs(TreeNode* root){
        if(!root) return;
        hashMap[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int> result;
        int maxi = 0;
        for(auto num:hashMap){
            maxi = max(maxi,num.second);
        }
        for(auto num:hashMap){
            if(num.second == maxi)
                result.push_back(num.first);
        }
        return result;
    }
};