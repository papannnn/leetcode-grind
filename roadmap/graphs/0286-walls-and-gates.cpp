const int INF = 2147483647;
struct Val {
    int y;
    int x;
    int val;
};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        deque<Val> q;
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push_back({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            Val data = q[0];
            q.pop_front();
            int y = data.y;
            int x = data.x;
            
            vector<vector<int>> dir = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}
            };
            for (int i = 0 ; i < dir.size(); i++) {
                int y1 = dir[i][0] + y;
                int x1 = dir[i][1] + x;

                if (y1 < 0 || x1 < 0 || y1 == grid.size() || x1 == grid[0].size() || grid[y1][x1] != INF) {
                    continue;
                }

                grid[y1][x1] = grid[y][x] + 1;
                q.push_back({y1, x1, -1});
            }
        }
    }
};
