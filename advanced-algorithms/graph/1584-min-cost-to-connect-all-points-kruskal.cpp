class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0 ; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool join(int x, int y) {
        if (find(x) == find(y)) {
            return false;
        }

        parent[find(y)] = find(x);
        return true;
    }

private:
    unordered_map<int, int> parent;
};

struct Destination {
    int point1;
    int point2;
    int cost;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto comparator = [] (const Destination& a, const Destination& b) {
            return a.cost < b.cost;
        };

        vector<Destination> edges;
        for (int i = 0 ; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++){ 
                int x2 = points[j][0];
                int y2 = points[j][1];
                int cost = abs(x1 - x2) + abs(y1 - y2);
                edges.push_back({ i, j, cost });
            }
        }

        sort(edges.begin(), edges.end(), comparator);

        DisjointSet ds(points.size());
        unordered_map<int, int> resultMapping;
        int result = 0;
        for (int i = 0 ; i < edges.size(); i++) {
            if (!ds.join(edges[i].point1, edges[i].point2)) {
                continue;
            }
            result += edges[i].cost;
        }

        return result;
    }
};
