struct Destination {
    int node;
    double cost;
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<Destination>> adjList(n);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            adjList[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        auto comparator = [] (const Destination& a, const Destination& b) {
            return a.cost < b.cost;
        };

        priority_queue<Destination, vector<Destination>, decltype(comparator)> q;
        
        q.push({ start_node, 1 });
        unordered_map<int, double> resultMapping;
        while (!q.empty() && resultMapping.find(end_node) == resultMapping.end()) {
            Destination curr = q.top();
            q.pop();

            if (resultMapping.find(curr.node) != resultMapping.end()) {
                continue;
            }

            resultMapping[curr.node] = curr.cost;

            for (int i = 0 ; i < adjList[curr.node].size(); i++) {
                q.push({ adjList[curr.node][i].node, adjList[curr.node][i].cost * resultMapping[curr.node] });
            }
        }

        if (resultMapping.find(end_node) == resultMapping.end()) {
            return 0;
        }
        
        return resultMapping[end_node];
    }
};