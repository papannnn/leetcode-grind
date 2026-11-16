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

    bool isValid(TreeNode* curr, int left, int right) {
        if (curr == nullptr) {
            return true;
        }
        
        if (curr->val <= left || curr->val >= right) {
            return false;
        }

        bool leftVal = true;
        bool rightVal = true;

        if (curr->left) {
            leftVal = isValid(curr->left, left, curr->val);
        }

        if (curr->right) {
            rightVal = isValid(curr->right, curr->val, right);
        }

        return leftVal && rightVal;
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, -1000000001, 1000000000);
    }
};
