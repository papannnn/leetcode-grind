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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> q;

        if (root) {
            q.push_back(root);
        }
        
        while (!q.empty()) {
            vector<int> temp;
            int currSize = q.size();
            while (currSize--) {
                TreeNode* curr = q.front();
                q.pop_front();
                temp.push_back(curr->val);
                if (curr->left) {
                    q.push_back(curr->left);
                }

                if (curr->right) {
                    q.push_back(curr->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
