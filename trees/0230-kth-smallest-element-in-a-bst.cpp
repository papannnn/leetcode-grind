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
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stk;
        TreeNode* curr = root;
        int cnt = 1;
        
        while (!stk.empty() || curr) {
            while (curr) {
                stk.push_back(curr);
                curr = curr->left;
            }

            curr = stk.back();
            stk.pop_back();

            if (cnt++ == k) {
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
};
