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
    int count = 0;
public:
    void palindromeCheck(TreeNode* root, unordered_map<int,int>& hashMap){
        if(!root) return;
        hashMap[root->val]++;
        
        if(!root->left && !root->right){
            int odd = 0;
            for(auto num:hashMap){
                if(num.second%2 == 1)
                    odd++;
            }
            if(odd <= 1)
                count++;
        }
        palindromeCheck(root->left,hashMap);
        palindromeCheck(root->right,hashMap);
        
        hashMap[root->val]--;
        if(hashMap[root->val] == 0)
            hashMap.erase(root->val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> hashMap;
        palindromeCheck(root,hashMap);
        return count;
    }
};