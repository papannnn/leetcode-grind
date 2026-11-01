class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk{};
        string tmp = "";
        for (int i = 0 ; i < path.size(); i++) {
            if (path[i] == '/') {
                pushDir(stk, tmp);
                tmp = "";
                continue;
            }

            tmp.push_back(path[i]);
        }

        pushDir(stk, tmp);
        string res = "/";
        int len = stk.size();
        for (int i = 0 ; i < len - 1; i++) {
            res += stk[i];
            res += "/";
        }

        if (!stk.empty()) res += stk.back();
        return res;
    }

    void pushDir(vector<string>& stk, string tmp) {
        if (tmp == "") {
            return;
        }

        if (tmp == ".") {
            return;
        }

        if (tmp == "..") {
            if (stk.size() > 0) {
                stk.pop_back();
            }
            return;
        }

        stk.push_back(tmp);
    }
};