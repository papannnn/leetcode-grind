class Solution {
public:
    
    int traverse(int idx, int amount, vector<int>& coins, vector<unordered_map<int, int>>& memo) {
        if (amount == 0) {
            return 1;
        }

        if (amount < 0) {
            return 0;
        }

        if (idx == coins.size()) {
            return 0;
        }

        if (memo[idx].find(amount) != memo[idx].end()) {
            return memo[idx][amount];
        }

        int res = 0;
        for (int i = idx; i < coins.size(); i++) {
            res += traverse(i, amount - coins[i], coins, memo);
        }

        memo[idx][amount] = res;

        return res;
    }

    int change(int amount, vector<int>& coins) {
        vector<unordered_map<int, int>> memo(coins.size());
        return traverse(0, amount, coins, memo);
    }
};
