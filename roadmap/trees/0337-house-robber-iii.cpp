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

    int traverse(TreeNode* curr, bool can) {
        if (curr == nullptr) {
            return 0;
        }

        if (dp[curr].find(can) != dp[curr].end()) {
            return dp[curr][can];
        }

        int skip = traverse(curr->left, true) + traverse(curr->right, true);
        int take = 0;
        if (can) {
            take = curr->val + traverse(curr->left, false) + traverse(curr->right, false);
        }

        dp[curr][can] = max(skip, take);
        return dp[curr][can];
    }

    int rob(TreeNode* root) {
        return traverse(root, true);
    }

private:
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
};