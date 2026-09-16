struct Pos {
    int y;
    int x;
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<Pos> q;

        int healthy = 0;
        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    healthy++;
                } else if (grid[i][j] == 2) {
                    q.push_back({i, j});
                }
            }
        }

        int res = 0;
        vector<Pos> direction = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        while (!q.empty() && healthy) {
            int len = q.size();
            res++;

            while (len--) {
                Pos pos = q.front();
                q.pop_front();

                int y = pos.y;
                int x = pos.x;

                for (int i = 0 ; i < direction.size(); i++) {
                    Pos dir = direction[i];

                    int posY = y + dir.y;
                    int posX = x + dir.x;

                    if (posY < 0 || posX < 0) {
                        continue;
                    } 

                    if (posY == grid.size() || posX == grid[0].size()) {
                        continue;
                    }

                    if (visited[posY][posX]) {
                        continue;
                    }

                    if (grid[posY][posX] == 0 || grid[posY][posX] == 2) {
                        continue;
                    }

                    visited[posY][posX] = true;
                    grid[posY][posX] = 2;
                    healthy--;
                    q.push_back({posY, posX});
                }
            }
        }
        return healthy == 0 ? res : -1;
    }
};
