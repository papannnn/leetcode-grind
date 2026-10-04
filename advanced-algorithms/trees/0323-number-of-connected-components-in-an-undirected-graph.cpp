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

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        int res = n;
        for (int i = 0 ; i < edges.size(); i++) {
            res -= ds.join(edges[i][0], edges[i][1]);
        }

        return res;
    }
};
