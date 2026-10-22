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
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }
    // this returns height, while traversing, keep track of max diameter
    int dfs(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int left = dfs(node->left, diameter);
        int right = dfs(node->right, diameter);

        diameter = max(diameter, left + right);

        // this is max depth aka height
        return 1 + max(left, right);
    }
};
