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
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        dfs(root, best);
        return best;
    }

    int dfs(TreeNode* root, int& best) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left, best);
        int right = dfs(root->right, best);
        best = std::max(best, right + left);
        return 1 + std::max(left, right);
    }
};
