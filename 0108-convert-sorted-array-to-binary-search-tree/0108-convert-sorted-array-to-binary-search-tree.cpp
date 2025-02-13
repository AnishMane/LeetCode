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
    
    TreeNode* BST(int left, int right, vector<int>& nums){
        if(left>right) return NULL;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BST(left,mid-1,nums);
        root->right = BST(mid+1,right,nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(0, nums.size()-1,nums);
    }
};