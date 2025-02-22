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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> nodeStack;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* newNode = new TreeNode(value);

            if (depth == nodeStack.size()) {
                if (!nodeStack.empty()) {
                    nodeStack.top()->left = newNode;
                }
            } 
            else {
                while (nodeStack.size() > depth) {
                    nodeStack.pop();
                }
                nodeStack.top()->right = newNode;
            }

            nodeStack.push(newNode);
        }

        while (nodeStack.size() > 1) {
            nodeStack.pop();
        }

        return nodeStack.top();
    }
};