class Solution {
public:

    int traverse(int idx, int total, int target, int sumStone, vector<int>& stones, vector<vector<int>>& memo) {
        if (idx == stones.size() || total >= target) {
            return abs(total - (sumStone - total));
        }

        if (memo[idx][total] != -1) {
            return memo[idx][total];
        }

        int skip = traverse(idx + 1, total, target, sumStone, stones, memo);
        int take = traverse(idx + 1, total + stones[idx], target, sumStone, stones, memo);
        memo[idx][total] = min(skip, take);
        return memo[idx][total];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0 ; i < stones.size(); i++) {
            sum += stones[i];
        }

        vector<vector<int>> memo(stones.size(), vector<int>(sum + 1, -1));
        return traverse(0, 0, sum / 2, sum, stones, memo);
    }
};