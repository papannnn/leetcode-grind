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
    TreeNode* traverse(TreeNode* curr, int target) {
        if (!curr) {
            return nullptr;
        }

        curr->left = traverse(curr->left, target);
        curr->right = traverse(curr->right, target);

        if (curr->left == nullptr && curr->right == nullptr && curr->val == target) {
            delete curr;
            return nullptr;
        }

        return curr;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return traverse(root, target);
    }
};