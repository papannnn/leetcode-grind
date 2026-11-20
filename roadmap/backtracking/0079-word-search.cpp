class Solution {
public:

    bool traverse(int y, int x, int idx, vector<vector<char>>& board, vector<vector<bool>>& visited, string& word) {
        if (idx == word.size()) {
            return true;
        }

        if (y < 0 || x < 0) {
            return false;
        }

        if (y >= board.size() || x >= board[0].size()) {
            return false;
        }

        if (board[y][x] != word[idx]) {
            return false;
        }

        if (visited[y][x]) {
            return false;
        }
        
        visited[y][x] = true;
        
        bool res =  traverse(y + 1, x, idx + 1, board, visited, word) || traverse(y, x + 1, idx + 1, board, visited, word) || traverse(y - 1, x, idx + 1, board, visited, word) || traverse(y, x - 1, idx + 1, board, visited, word); 
        
        visited[y][x] = false;
        return res;
    }


    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (!res) {
                    res = traverse(i, j, 0, board, visited, word);
                }
            }
        }
        return res;
    }
};
