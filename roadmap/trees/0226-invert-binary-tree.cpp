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

    TreeNode* invert(TreeNode* curr) {
        if (curr) {
            swap(curr->left, curr->right);
            invert(curr->left);
            invert(curr->right);
        }
        return curr;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};
