class Solution {
public:
    int islandCount(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || col < 0) {
            return 0;
        }

        if (row == grid.size() || col == grid[0].size()) {
            return 0;
        }

        if (grid[row][col] == '0') {
            return 0;
        }

        if (visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        islandCount(grid, visited, row + 1, col);
        islandCount(grid, visited, row, col + 1);
        islandCount(grid, visited, row - 1, col);
        islandCount(grid, visited, row, col - 1);
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        
        int res = 0;
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[i].size(); j++) {
                res += islandCount(grid, visited, i, j);
            }
        }
        return res;
    }
};
