class DisjointSet {
public:
    DisjointSet(int amt) {
        for (int i = 1; i <= amt; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        while (n != parent[n]) {
            parent[n] = parent[parent[n]];
            n = parent[n];
        }
        return n;
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

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        DisjointSet ds(edges.size());

        for (int i = 0 ; i < edges.size(); i++) {
            if (!ds.join(edges[i][0], edges[i][1])) {
                res = edges[i];
            }
        }
        return res;
    }
};
