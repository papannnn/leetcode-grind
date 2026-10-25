class Solution {
public:

    bool isValid(int y, int x, vector<vector<char>>& board) {
        char val = board[y][x];

        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cnt += board[(y / 3 * 3) + i][(x / 3 * 3) + j] == val;
            }
        }

        if (cnt > 1) {
            return false;
        }

        cnt = 0;
        for (int i = 0; i < 9; i++) {
            cnt += board[y][i] == val;
        }

        if (cnt > 1) {
            return false;
        }

        cnt = 0;
        for (int i = 0; i < 9; i++) {
            cnt += board[i][x] == val;
        }

        if (cnt > 1) {
            return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0 ; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    valid &= isValid(i, j, board);
                }
            }
        }
        return valid;
    }
};
