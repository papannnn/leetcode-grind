class Solution {
public:

    int traverse(int idx1, int idx2, string& word1, string& word2, vector<vector<int>>& memo) {
        // Insert
        if (idx1 == word1.size() && idx2 < word2.size()) {
            return 1 + traverse(idx1, idx2 + 1, word1, word2, memo);
        }

        // Delete
        if (idx1 < word1.size() && idx2 == word2.size()) {
            return 1 + traverse(idx1 + 1, idx2, word1, word2, memo);
        }

        // Match
        if (idx1 == word1.size() && idx2 == word2.size()) {
            return 0;
        }

        if (memo[idx1][idx2] != -1) {
            return memo[idx1][idx2];
        }

        if (word1[idx1] == word2[idx2]) {
            return traverse(idx1 + 1, idx2 + 1, word1, word2, memo);
        }

        int replace = 1 + traverse(idx1 + 1, idx2 + 1, word1, word2, memo);
        int insert = 1 + traverse(idx1, idx2 + 1, word1, word2, memo);
        int del = 1 + traverse(idx1 + 1, idx2, word1, word2, memo);

        memo[idx1][idx2] = min(del, min(replace, insert));

        return min(del, min(replace, insert));
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return traverse(0, 0, word1, word2, memo);
    }
};
