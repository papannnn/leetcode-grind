class Solution {
public:

    int traverse(int idx, string& s, vector<string>& dict) {
        if (idx == s.size()) {
            return 0;
        }

        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }

        int skip = 1 + traverse(idx + 1, s, dict);
        int take = 1e9;
        for (string &str : dict) {
            int j = idx;
            int len = s.size() - j + 1;
            if (len < str.size()) {
                continue;
            }

            bool valid = true;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != s[j++]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                take = min(take, traverse(idx + str.size(), s, dict));
            }
        }
        
        dp[idx] = min(take, skip);
        return min(take, skip);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        return traverse(0, s, dictionary);
    }

private:
    unordered_map<int, int> dp;
};