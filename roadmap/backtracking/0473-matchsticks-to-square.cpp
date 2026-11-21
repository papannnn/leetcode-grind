class Solution {
public:

    bool traverse(int idx, int up, int down, int left, int right, vector<int>& matchsticks) {
        if (up > len || down > len || left > len || right > len) {
            return false;
        }

        if (idx == matchsticks.size()) {
            return up == down && up == left && up == right;
        }

        int val = matchsticks[idx];
        return traverse(idx + 1, up + val, down, left, right, matchsticks) || traverse(idx + 1, up, down + val, left, right, matchsticks) || traverse(idx + 1, up, down, left + val, right, matchsticks) || traverse(idx + 1, up, down, left, right + val, matchsticks);
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int i = 0 ; i < matchsticks.size(); i++) {
            sum += matchsticks[i];
        }

        if (sum % 4 != 0) {
            return false;
        }

        len = sum / 4;

        for (int i = 0 ; i < matchsticks.size(); i++) {
            if (matchsticks[i] > len) {
                return false;
            }
        }

        return traverse(0, 0, 0, 0, 0, matchsticks);
    }
private:
    int len{};

};