class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        _stk.push_back(val);
        if (_stkMin.empty()) {
            _stkMin.push_back(val);
        } else {
            int minVal = min(val, _stkMin.back());
            _stkMin.push_back(minVal);
        }
    }
    
    void pop() {
        _stk.pop_back();
        _stkMin.pop_back();
    }
    
    int top() {
        return _stk.back();
    }
    
    int getMin() {
        return _stkMin.back();
    }

private:
    vector<int> _stk;
    vector<int> _stkMin;
};
