class Solution {
public:

    bool traverse(int parent, int val, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
        if (visited[val]) {
            return false;
        }

        visited[val] = true;
        bool res = true;
        for (int i = 0 ; i < adjList[val].size(); i++) {
            if (adjList[val][i] == parent) continue;
            res &= traverse(val, adjList[val][i], adjList, visited);
        }
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n);
        bool res = traverse(-1, 0, adjList, visited);
        for (int i = 0; i < visited.size(); i++) {
            res &= visited[i];
        }
        return res;
    }
};
