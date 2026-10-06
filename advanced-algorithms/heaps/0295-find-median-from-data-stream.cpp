class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);

        if (maxHeap.size() > 0 && minHeap.size() > 0) {
            if (maxHeap.top() > minHeap.top()) {
                int val = maxHeap.top();
                maxHeap.pop();
                minHeap.push(val);
            }
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (static_cast<double>(minHeap.top()) + static_cast<double>(maxHeap.top())) / 2;
        } else {
            if (minHeap.size() > maxHeap.size()) {
                return minHeap.top();
            } else {
                return maxHeap.top();
            }
        }
    }

private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
