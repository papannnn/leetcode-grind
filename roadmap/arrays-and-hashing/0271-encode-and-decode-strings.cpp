class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string res = "";
        for (int i = 0 ; i < strs.size(); i++) {
            res += strs[i];
            res += '\0';
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr = "";
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == '\0') {
                res.push_back(curr);
                curr = "";
            } else {
                curr += s[i];
            }
        }
        return res;
    }
};
