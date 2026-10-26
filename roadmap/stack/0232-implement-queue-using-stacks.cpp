class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push_back(x);
    }
    
    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push_back(stk1.back());
                stk1.pop_back();
            }
        }
        int val = stk2.back();
        stk2.pop_back();
        return val;
    }
    
    int peek() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push_back(stk1.back());
                stk1.pop_back();
            }
        }
        return stk2.back();
    }
    
    bool empty() {
        return stk1.size() == 0 && stk2.size() == 0;
    }

private:
    vector<int> stk1;
    vector<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */