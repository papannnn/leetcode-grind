struct Destination {
    int target;
    int cost;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Destination>> adjList(n + 1);

        for (int i = 0 ; i < times.size(); i++) {
            adjList[times[i][0]].push_back({ times[i][1], times[i][2] });
        }
        
        auto comparator = [] (const Destination& a, const Destination& b) {
            return a.cost > b.cost;
        };

        priority_queue<Destination, vector<Destination>, decltype(comparator)> q;
        q.push({ k, 0 });

        unordered_map<int, int> bestCostMapping;
        while (!q.empty()) {
            Destination curr = q.top();
            q.pop();

            if (bestCostMapping.find(curr.target) != bestCostMapping.end()) {
                continue;
            }

            bestCostMapping[curr.target] = curr.cost;
            for (int i = 0 ; i < adjList[curr.target].size(); i++) {
                Destination d = adjList[curr.target][i];
                q.push({ d.target, d.cost + curr.cost });
            }
        }

        int res = 0;
        for (auto &m : bestCostMapping) {
            res = max(res, m.second);
        }

        return bestCostMapping.size() == n ? res : -1;
    }
};
