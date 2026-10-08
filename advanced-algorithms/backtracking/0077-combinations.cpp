class Solution {
public:

    void traverse(int idx, int n, int k, vector<int>& curr) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i <= n; i++) {
            curr.push_back(i);
            traverse(i + 1, n, k, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        traverse(1, n, k, curr);
        return res;
    }

private:
    vector<vector<int>> res;
};