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
class FindElements {
public:
    TreeNode* head = new TreeNode();

    void recursion(int prev, TreeNode* cur){
        if(!cur) return;
        cur->val = prev;
        recursion(prev*2+1,cur->left);
        recursion(prev*2+2,cur->right);
    }

    FindElements(TreeNode* root) {
        head = root;
        TreeNode* cur = root;
        cur->val = 0;
        recursion(0,cur);
    }

    bool findT(TreeNode* cur, int target){
        if(!cur) return false;
        if(cur->val == target) return true;
        bool left = findT(cur->left,target);
        bool right = findT(cur->right,target);

        return left||right;
    }
    
    bool find(int target) {
        return findT(head,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */