class Solution {
public:
    int traverse(int y, int x, int m, int n, vector<vector<int>> &memo) {
        if (y == m) {
            return 0;
        }

        if (x == n) {
            return 0;
        }

        if (y == m - 1 && x == n - 1) {
            return 1;
        }

        if (memo[y][x] > 0) {
            return memo[y][x];
        }

        memo[y][x] = traverse(y + 1, x, m, n, memo) + traverse(y, x + 1, m, n, memo);
        return memo[y][x];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n));
        return traverse(0, 0, m, n, memo);
    }
};
