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
    TreeNode* build(vector<int>& preorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int val = preorder[idx++];
        TreeNode* node = new TreeNode(val);

        int mid = mapping[val];

        node->left = build(preorder, l, mid - 1);
        node->right = build(preorder, mid + 1, r);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0 ; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

private:
    unordered_map<int, int> mapping;
    int idx{};
};
