class Solution {
public:

    void traverse(int idx, vector<vector<char>>& mapping, string& digits, string curr) {
        if (idx == digits.size()) {
            if (curr.size() == 0) {
                return;
            }
            res.push_back(curr);
            return;
        }

        char c = digits[idx];
        for (int i = 0 ; i < mapping[c - '0'].size(); i++) {
            traverse(idx + 1, mapping, digits, curr + mapping[c - '0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> mapping = {
            {}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
        };

        traverse(0, mapping, digits, "");
        return res;
    }

private:
    vector<string> res;
};
