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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> q;

        if (root != nullptr) {
            q.push_back(root);
        }

        while (q.size()) {
            int currSize = q.size();
            vector<int> temp;
            while (currSize--) {
                TreeNode* curr = q.front();
                q.pop_front();

                if (curr->left != nullptr) {
                    q.push_back(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push_back(curr->right);
                }
                temp.push_back(curr->val);
            }
            res.push_back(temp.back());
        }

        return res;
    }
};
