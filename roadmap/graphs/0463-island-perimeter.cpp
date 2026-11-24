class Solution {
public:
    int traverse(int y, int x, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (y < 0 || x < 0 || y == grid.size() || x == grid[0].size() || grid[y][x] == 0) {
            return 1;
        }

        if (visited[y][x]) {
            return 0;
        }
        visited[y][x] = true;
        int res = traverse(y + 1, x, grid, visited) + traverse(y - 1, x, grid, visited) + traverse(y, x + 1, grid, visited) + traverse(y, x - 1, grid, visited);
        return res;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    return traverse(i, j, grid, visited);
                }
            }
        }
        return 0;
    }
};