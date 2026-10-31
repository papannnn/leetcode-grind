struct Data {
    int streak;
    int val;
};

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!stk.empty() && stk.back().val <= price) {
            res += stk.back().streak;
            stk.pop_back();
        }
        stk.push_back({ res, price });
        return res;
    }
private:
    vector<Data> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */