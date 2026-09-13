class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0 ; i < nums.size(); i++) {
            q.push(nums[i]);
            if (q.size() > k) {
                q.pop();
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }

private:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
};
