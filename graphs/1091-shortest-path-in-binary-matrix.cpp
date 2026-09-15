struct Pos {
    int y;
    int x;
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int posY = 0;
        int posX = 0;

        vector<Pos> temp = {
            {1, 0}, {0, 1},
            {-1, 0}, {0, -1},
            {-1, -1}, {1, 1},
            {-1, 1}, {1, -1}
        };

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        deque<Pos> q;
        if (grid[posY][posX] == 0) {
            q.push_back({posY, posX});
            visited[posY][posX] = true;
        }

        int res = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                Pos pos = q.front();
                q.pop_front();
                posY = pos.y;
                posX = pos.x;

                for (int i = 0 ; i < temp.size(); i++) {
                    Pos tempPost = temp[i];

                    int tempPostY = posY + tempPost.y;
                    int tempPostX = posX + tempPost.x;

                    if (tempPostY < 0 || tempPostX < 0) {
                        continue;
                    }

                    if (tempPostY == grid.size() || tempPostX == grid[0].size()) {
                        continue;
                    }

                    if (grid[tempPostY][tempPostX] == 1) {
                        continue;
                    }

                    if (visited[tempPostY][tempPostX]) {
                        continue;
                    }

                    visited[tempPostY][tempPostX] = true;
                    q.push_back({tempPostY, tempPostX});
                }

                if (posY == grid.size() - 1 && posX == grid[0].size() - 1) {
                    return res;
                }
            }
            
            res++;
        }
        return -1;
    }
};