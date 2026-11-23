struct Task {
    int idx;
    int startTime;
    int processTime;
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        deque<Task> vecTask;
        for (int i = 0 ; i < tasks.size(); i++) {
            vecTask.push_back({i, tasks[i][0], tasks[i][1]});
        }

        sort(vecTask.begin(), vecTask.end(), [] (const Task& a, const Task& b) {
            return a.startTime < b.startTime;
        });

        auto comp = [] (const Task& a, const Task&b) {
            if (a.processTime != b.processTime) {
                return a.processTime > b.processTime;
            }
            return a.idx > b.idx;
        };

        priority_queue<Task, vector<Task>, decltype(comp)> q;
        vector<int> res;
        int time = 0;
        while (!q.empty() || !vecTask.empty()) {

            if (q.empty() && time < vecTask[0].startTime) {
                time = vecTask[0].startTime;
            }

            while (!vecTask.empty() && time >= vecTask[0].startTime) {
                q.push(vecTask[0]);
                vecTask.pop_front();
            }
            
            Task t = q.top();
            q.pop();
            time += t.processTime;
            res.push_back(t.idx);
        }
        return res;
    }
};