class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0 ; i <= n; i++) {
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

    bool join(int y, int x) {
        if (find(x) == find(y)) {
            return false;
        }

        parent[find(y)] = find(x);
        return true;
    }

private:
    unordered_map<int, int> parent;
};

struct Edge {
    int from;
    int to;
    int weight;
    int idx;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> arrEdge;
        for (int i = 0 ; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            arrEdge.push_back({ from, to, weight, i });
        }

        sort(arrEdge.begin(), arrEdge.end(), [] (const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        int mstCost = 0;
        DisjointSet ds(edges.size());
        for (int i = 0 ; i < arrEdge.size(); i++) {
            if (!ds.join(arrEdge[i].from, arrEdge[i].to)) {
                continue;
            }
            mstCost += arrEdge[i].weight;
        }
    
        vector<vector<int>> res(2);
        for (int i = 0 ; i < arrEdge.size(); i++) {
            DisjointSet tempDisjointSet(arrEdge.size());
            int currMstCost = 0;
            int cnt = 0;
            for (int j = 0 ; j < arrEdge.size(); j++) {
                if (j == i) {
                    continue;
                }

                if (!tempDisjointSet.join(arrEdge[j].from, arrEdge[j].to)) {
                    continue;
                }
                cnt++;
                currMstCost += arrEdge[j].weight;
            }
            
            if (currMstCost > mstCost || cnt != n - 1) {
                res[0].push_back(arrEdge[i].idx);
                continue;
            }

            DisjointSet anotherDisjointSet(arrEdge.size());

            int currMstCost1 = arrEdge[i].weight;
            anotherDisjointSet.join(arrEdge[i].from, arrEdge[i].to);
            for (int j = 0 ; j < arrEdge.size(); j++) {
                if (!anotherDisjointSet.join(arrEdge[j].from, arrEdge[j].to)) {
                    continue;
                }

                currMstCost1 += arrEdge[j].weight;
            }

            if (currMstCost1 == mstCost) {
                res[1].push_back(arrEdge[i].idx);
            }
        }

        return res;
    }
};