class Solution {
public:
    void traverse(int open, int close, int n, string s) {
        if (close == n) {
            res.push_back(s);
            return;
        }

        if (open < n) {
            traverse(open + 1, close, n, s + '(');
        }

        if (close < open) {
            traverse(open, close + 1, n, s + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        traverse(0, 0, n, "");
        return res;
    }

private:
    vector<string> res;
};
