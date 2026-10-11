struct Position {
    int y;
    int x;
    int cost;
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto comparator = [] (const Position& a, const Position& b) {
            return a.cost > b.cost;
        };

        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        priority_queue<Position, vector<Position>, decltype(comparator)> q;
        q.push({ 0, 0, grid[0][0] });
        while (!q.empty() && !visited[visited.size() - 1][visited[0].size() - 1]) {
            Position pos = q.top();
            q.pop();

            if (pos.y < 0 || pos.x < 0) {
                continue;
            }

            if (pos.y == grid.size() || pos.x == grid[0].size()) {
                continue;
            }

            if (visited[pos.y][pos.x]) {
                continue;
            }

            visited[pos.y][pos.x] = true;
            res = max(res, pos.cost);

            if (pos.y != 0) {
                q.push({ pos.y - 1, pos.x, grid[pos.y - 1][pos.x] });
            }

            if (pos.x != 0) {
                q.push({ pos.y, pos.x - 1, grid[pos.y][pos.x - 1] });
            }

            if (pos.y != grid.size() - 1) {
                q.push({ pos.y + 1, pos.x, grid[pos.y + 1][pos.x] });
            }

            if (pos.x != grid[0].size() - 1) {
                q.push({ pos.y, pos.x + 1, grid[pos.y][pos.x + 1] });
            }
        }
        return res;
    }
};
