class Solution {
public:
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &memo) {
        if (i == s1.size()) {
            return 0;
        }
        
        if (j == s2.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s1[i] == s2[j]) {
            return lcs(s1, s2, i + 1, j + 1, memo) + 1;
        }
        
        int take1 = lcs(s1, s2, i + 1, j, memo);
        int take2 = lcs(s1, s2, i, j + 1, memo);
        memo[i][j] = max(take1, take2);
        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return lcs(text1, text2, 0, 0, memo);
    }
};
