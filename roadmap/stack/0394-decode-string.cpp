class Solution {
public:


    string decodeString(string s) {
        vector<char> stk;
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] != ']') {
                stk.push_back(s[i]);
                continue;
            }

            string str = "";
            while (stk.back() != '[') {
                str.push_back(stk.back());
                stk.pop_back();
            }
            stk.pop_back();
            string num = "";
            while (!stk.empty() && isdigit(stk.back())) {
                num.push_back(stk.back());
                stk.pop_back();
            }

            reverse(str.begin(), str.end());
            reverse(num.begin(), num.end());
            int iteration = stoi(num);
            string res = "";
            for (int i = 0 ; i < iteration; i++) {
                res += str;
            }
            
            for (int i = 0 ; i < res.size(); i++) {
                stk.push_back(res[i]);
            }
        }

        string result = "";
        for (int i = 0 ; i < stk.size(); i++) {
            result += stk[i];
        }
        return result;
    }
};