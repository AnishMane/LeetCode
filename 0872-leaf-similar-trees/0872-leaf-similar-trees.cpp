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
    void checkSimilar(TreeNode* root, vector<int>& nums){
        if(!root) return;
        if(!root->left && !root->right){
            nums.push_back(root->val);
            return;
        }
        checkSimilar(root->left,nums);
        checkSimilar(root->right,nums);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1;
        vector<int> nums2;
        checkSimilar(root1,nums1);
        checkSimilar(root2,nums2);
        return nums1==nums2;
    }
};