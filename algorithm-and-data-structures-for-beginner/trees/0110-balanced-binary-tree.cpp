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

struct Result {
    bool valid;
    int height;
};

class Solution {
public:
    Result traverse(TreeNode* root) {
        if (root == nullptr) {
            return {true, 0};
        }

        Result left = traverse(root->left);
        Result right = traverse(root->right);
        bool valid = left.valid && right.valid && abs(left.height - right.height) <= 1;
        return {valid, max(left.height, right.height) + 1};
    }

    bool isBalanced(TreeNode* root) {
        return traverse(root).valid;
    }
};
