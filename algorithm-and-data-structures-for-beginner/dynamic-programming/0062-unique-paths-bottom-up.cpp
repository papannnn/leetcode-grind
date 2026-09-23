class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            memo[m - 1][i] = 1;
        }

        for (int i = 0; i < m; i++) {
            memo[i][n - 1] = 1;
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                memo[i][j] = memo[i + 1][j] + memo[i][j + 1];
            }
        }

        return memo[0][0];
    }
};
