class Solution {
public:

    int traverse(int idx1, int idx2, string& s, string& t, vector<vector<int>>& memo) {
        if (idx2 == t.size()) {
            return 1;
        }

        if (idx1 == s.size()) {
            return 0;
        }

        if (memo[idx1][idx2] != -1) {
            return memo[idx1][idx2];
        }

        int take = 0;
        if (s[idx1] == t[idx2]) {
            take = traverse(idx1 + 1, idx2 + 1, s, t, memo);
        }
        int skip = traverse(idx1 + 1, idx2, s, t, memo);

        memo[idx1][idx2] = take + skip;
        return take + skip;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
        return traverse(0, 0, s, t, memo);
    }
};
