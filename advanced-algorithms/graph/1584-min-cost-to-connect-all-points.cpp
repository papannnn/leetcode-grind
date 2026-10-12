struct Destination {
    int idx;
    int cost;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<Destination>> adjList;

        for (int i = 0 ; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int cost = abs(x1 - x2) + abs(y1 - y2);
                
                adjList[i].push_back({ j, cost });
                adjList[j].push_back({ i, cost });
            }
        }

        auto comparator = [] (const Destination& a, const Destination& b) {
            return a.cost > b.cost;
        };
        priority_queue<Destination, vector<Destination>, decltype(comparator)> q;
        q.push({ 0, 0 });
        unordered_map<int, int> resultMapping;
        int res = 0;

        while (!q.empty() && resultMapping.size() < points.size()) {
            Destination curr = q.top();
            q.pop();

            if (resultMapping.find(curr.idx) != resultMapping.end()) {
                continue;
            }

            resultMapping[curr.idx] = curr.cost;
            res += curr.cost;

            for (int i = 0; i < adjList[curr.idx].size(); i++) {
                q.push(adjList[curr.idx][i]);
            }
        }

        return res;
    }
};
