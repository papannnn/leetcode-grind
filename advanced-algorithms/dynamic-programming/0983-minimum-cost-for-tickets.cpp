class Solution {
public:

    int traverse(int idx, int upTo, vector<int>& days, vector<int>& costs, vector<vector<int>>& memo) {
        if (idx == days.size()) {
            return 0;
        }

        if (memo[idx][upTo] != -1) {
            return memo[idx][upTo];
        }

        if (upTo > days[idx]) {
            return traverse(idx + 1, upTo, days, costs, memo);
        }
        
        int oneDay = costs[0] + traverse(idx, days[idx] + 1, days, costs, memo);
        int sevenDay = costs[1] + traverse(idx, days[idx] + 7, days, costs, memo);
        int thirtyDay = costs[2] + traverse(idx, days[idx] + 30, days, costs, memo);

        memo[idx][upTo] = min(min(oneDay, sevenDay), thirtyDay);

        return memo[idx][upTo];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> memo(days.size(), vector<int>(400, -1));
        return traverse(0, days[0], days, costs, memo);
    }
};