class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        cnt[val]++;
        stk[cnt[val]].push_back(val);
        maxCnt = max(maxCnt, cnt[val]);
    }
    
    int pop() {
        int res = stk[maxCnt].back();
        stk[maxCnt].pop_back();
        cnt[res]--;
        if (stk[maxCnt].size() == 0) {
            maxCnt--;
        }
        return res;
    }

private:
    unordered_map<int, int> cnt;
    unordered_map<int, vector<int>> stk;
    int maxCnt{0};
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */