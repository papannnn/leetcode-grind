class Solution {
public:

    bool traverse(int idx1, int idx2, int idx3, string& s1, string& s2, string& s3, vector<vector<int>>& memo) {
        if (idx1 == s1.size() && idx2 == s2.size() && idx3 == s3.size()) {
            return true;
        }

        if (idx3 == s3.size()) {
            return false;
        }

        if (memo[idx1][idx2] != -1) {
            return memo[idx1][idx2];
        }
        
        bool res = false;
        if (idx1 < s1.size() && s1[idx1] == s3[idx3]) {
            res |= traverse(idx1 + 1, idx2, idx3 + 1, s1, s2, s3, memo);
        }

        if (idx2 < s2.size() && s2[idx2] == s3[idx3]) {
            res |= traverse(idx1, idx2 + 1, idx3 + 1, s1, s2, s3, memo);
        }

        return memo[idx1][idx2] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return traverse(0, 0, 0, s1, s2, s3, memo);
    }
};
