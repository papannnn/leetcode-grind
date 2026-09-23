class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;

        bool valid = true;
        for (int i = 0 ; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                stk.push_back(s[i]);
                for (int j = 0; j < stk.size(); j++) {
                    cout << stk[j];
                }
                cout << endl;
                continue;
            }

            if (stk.size() == 0) {
                valid = false;
                continue;
            }

            if (s[i] == '}') {
                valid &= stk.back() == '{';
            } else if (s[i] == ']') {
                valid &= stk.back() == '[';
            } else if (s[i] == ')') {
                valid &= stk.back() == '(';
            }
            
            if (valid) {
                stk.pop_back();
            }
        }
        return valid && stk.size() == 0;
    }
};
