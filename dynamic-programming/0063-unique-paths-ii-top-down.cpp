class Solution {
public:
    int traverse(int y, int x, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (y == grid.size()) {
            return 0;
        }

        if (x == grid[0].size()) {
            return 0;
        }

        if (memo[y][x]) {
            return memo[y][x];
        }

        if (grid[y][x]) {
            return 0;
        }

        if (y == grid.size() - 1 && x == grid[0].size() - 1) {
            return 1;
        }

        memo[y][x] = traverse(y + 1, x, grid, memo) + traverse(y, x + 1, grid, memo);
        return memo[y][x];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size()));
        return traverse(0, 0, grid, memo);
    }
};