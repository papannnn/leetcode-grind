struct Data {
    int idx;
    int val;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<Data> stk;
        
        vector<int> res(temperatures.size());
        for (int i = 0 ; i < temperatures.size(); i++) {
            while (!stk.empty() && stk.back().val < temperatures[i]) {
                res[stk.back().idx] = i - stk.back().idx;
                stk.pop_back();
            }

            stk.push_back({ i, temperatures[i] });
        }
        return res;
    }
};
