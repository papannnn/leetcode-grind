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
    bool traverse(TreeNode* curr, int sum, int targetSum) {
        if (curr == nullptr) {
            return false;
        }

        sum += curr->val;
        if (curr->left == nullptr && curr->right == nullptr) {
            return sum == targetSum;
        }

        return traverse(curr->left, sum, targetSum) || traverse(curr->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, 0, targetSum);
    }
};