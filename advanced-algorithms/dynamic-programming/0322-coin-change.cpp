class Solution {
public:

    int traverse(int idx, long long curr, long long target, vector<int>& coins, vector<vector<int>>& memo) {
        if (curr == target) {
            return 0;
        }

        if (idx == coins.size()) {
            return 1e6;
        }

        if (memo[idx][curr] != -1) {
            return memo[idx][curr];
        }

        int res = traverse(idx + 1, curr, target, coins, memo);
        if (curr + coins[idx] <= target) {
            res = min(res, 1 + traverse(idx, curr + coins[idx], target, coins, memo));
        }

        memo[idx][curr] = res;
        return memo[idx][curr];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int res = traverse(0, 0, amount, coins, memo);
        if (res == 1e6) {
            return -1;
        }
        return res;
    }
};
