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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(!root) {
            return res;
        }

        std::queue<TreeNode *> nodes;
        
        nodes.push(root);

        while(!nodes.empty()) {
            vector<int> level;
            int size = nodes.size();

            for(int i = nodes.size(); i > 0; --i) {
                TreeNode *top = nodes.front();
                nodes.pop();
                if(top) {
                    level.push_back(top->val);
                    nodes.push(top->left);
                    nodes.push(top->right);
                }
            }

            if(!level.empty()) {
                res.push_back(level);
            }
        }

        return res;
        
    }
};
