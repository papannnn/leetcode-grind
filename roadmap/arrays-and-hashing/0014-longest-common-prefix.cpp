class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        size_t maxLen = 0;
        for (int i = 0 ; i < strs.size(); i++) {
            maxLen = max(maxLen, strs[i].size());
        }

        bool valid = true;
        for (int i = 0 ; i < maxLen && valid; i++) {
            for (int j = 0 ; j < strs.size(); j++) {
                if (i == strs[j].size() || strs[0][i] != strs[j][i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                res.push_back(strs[0][i]);
            }
        }
        return res;
    }
};