class Solution {
public:
    void traverse(vector<vector<int>>& image, vector<vector<bool>>& visited, int r, int c, int sameColor, int color) {
        if (r < 0 || c < 0) {
            return;
        }

        if (r == image.size()) {
            return;
        }

        if (c == image[0].size()) {
            return;
        }

        if (image[r][c] != sameColor) {
            return;
        }

        if (visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        image[r][c] = color;

        traverse(image, visited, r + 1, c, sameColor, color);
        traverse(image, visited, r, c + 1, sameColor, color);
        traverse(image, visited, r - 1, c, sameColor, color);
        traverse(image, visited, r, c - 1, sameColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
        int sameColor = image[sr][sc];
        traverse(image, visited, sr, sc, sameColor, color);
        return image;
    }
};