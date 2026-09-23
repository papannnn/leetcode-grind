class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n));

        if (obstacleGrid[m - 1][n - 1] == 0) {
            memo[m - 1][n - 1] = 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (obstacleGrid[m - 1][i] == 1) {
                memo[m - 1][i] = 0;
            } else {
                memo[m - 1][i] = memo[m - 1][i + 1];
            }
        }

        for (int i = m - 2; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 1) {
                memo[i][n - 1] = 0;
            } else {
                memo[i][n - 1] = memo[i + 1][n - 1];
            }
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) continue;
                memo[i][j] = memo[i + 1][j] + memo[i][j + 1];
            }
        }
        
        return memo[0][0];
    }
};