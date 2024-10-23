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
class BSTIterator {
private:
    vector<int> result;
    int pntr;
public:
    
    void BST(TreeNode*root){
        if(!root) return;
        BST(root->left);
        result.push_back(root->val);
        BST(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        BST(root);
        pntr = -1;
    }
    
    int next() {
        pntr++;
        return result[pntr];
    }
    
    bool hasNext() {
        if(pntr+1 < result.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */