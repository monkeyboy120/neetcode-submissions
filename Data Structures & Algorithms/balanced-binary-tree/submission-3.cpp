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
        bool isBal = true;
        dfs(root, isBal);
        return isBal;
    }

    int dfs(TreeNode *root, bool &isBal) {
        if(!root) return 0;

        int left = dfs(root->left, isBal);
        int right = dfs(root->right, isBal);

        if(abs(right - left) > 1) {
            isBal = false;
        }

        return 1 + max(left, right);
    }
};
