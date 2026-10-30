class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;
        for (int i = 0 ; i < tokens.size(); i++) {
            string str = tokens[i];
            if (str == "+") {
                int val2 = stk.back(); stk.pop_back();
                int val1 = stk.back(); stk.pop_back();
                stk.push_back(val1 + val2);
            } else if (str == "-") {
                int val2 = stk.back(); stk.pop_back();
                int val1 = stk.back(); stk.pop_back();
                stk.push_back(val1 - val2);
            } else if (str == "*") {
                int val2 = stk.back(); stk.pop_back();
                int val1 = stk.back(); stk.pop_back();
                stk.push_back(val1 * val2);
            } else if (str == "/") {
                int val2 = stk.back(); stk.pop_back();
                int val1 = stk.back(); stk.pop_back();
                stk.push_back(val1 / val2);
            } else {
                stk.push_back(stoi(str));
            }
        }
        return stk.back();
    }
};
