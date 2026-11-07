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
    bool isBalanced(TreeNode* root) {
       int height = 0;
       return dfs(root, height); 
    }

    bool dfs(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }

        int leftHeight = 0;
        int rightHeight = 0;

        bool leftBalanced = dfs(root->left, leftHeight);
        bool rightBalanced = dfs(root->right, rightHeight);

        // bubble up height to parent
        height = 1 + max(leftHeight, rightHeight);

        return leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;
    }
};
