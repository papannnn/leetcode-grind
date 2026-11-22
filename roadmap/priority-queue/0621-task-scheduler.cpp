struct NextTask {
    int val;
    int time;
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        for (int i = 0 ; i < tasks.size(); i++) {
            cnt[tasks[i] - 'A']++;
        }

        priority_queue<int, vector<int>, less<int>> heap;
        for (int i = 0 ; i < cnt.size(); i++) {
            if (cnt[i] > 0)
                heap.push(cnt[i]);
        }
        deque<NextTask> q;
        int time = 0;
        while (!heap.empty() || !q.empty()) {
            time++;

            if (heap.empty()) {
                time = q[0].time;
            } else {
                int val = heap.top() - 1;
                heap.pop();
                if (val > 0) {
                    q.push_back({val, time + n});
                }
            }

            if (!q.empty() && q[0].time <= time) {
                heap.push(q[0].val);
                q.pop_front();
            }
        }

        return time;
    }
};
