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

    bool findSubRoot(TreeNode* curr, TreeNode* subRoot) {
        if (!curr) {
            return false;
        }

        if (curr->val == subRoot->val && check(curr, subRoot)) {
            return true;
        }

        bool left = findSubRoot(curr->left, subRoot);
        bool right = findSubRoot(curr->right, subRoot);
        return left || right;
    }

    bool check(TreeNode* curr, TreeNode* subRootCurr) {
        if (!curr && !subRootCurr) {
            return true;
        }

        if (!subRootCurr) {
            return false;
        }

        if (!curr) {
            return false;
        }

        if (curr->val != subRootCurr->val) {
            return false;
        }

        return check(curr->left, subRootCurr->left) && check(curr->right, subRootCurr->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return findSubRoot(root, subRoot);
    }
};
