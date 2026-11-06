class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = 1e9;
        int res = 0;
        for (int i = 0 ; i < prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            res = max(res, prices[i] - minVal);
        }
        return res;
    }
};
