class Solution {
public:

    bool traverse(int course, vector<vector<int>>& adjList, unordered_set<int>& visited, unordered_set<int>& journey) {
        if (journey.find(course) != journey.end()) {
            return false;
        }

        if (visited.find(course) != visited.end()) {
            return true;
        }

        journey.insert(course);
        visited.insert(course);
        bool valid = true;
        for (int i = 0 ; i < adjList[course].size(); i++) {
            valid &= traverse(adjList[course][i], adjList, visited, journey);
        }

        journey.erase(course);
        if (valid) {
            res.push_back(course);
        }

        return valid;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (int i = 0 ; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int need = prerequisites[i][1];
            adjList[course].push_back(need);
        }

        unordered_set<int> visited;
        unordered_set<int> journey;
        for (int i = 0 ; i < numCourses; i++) {
            if (!traverse(i, adjList, visited, journey)) {
                return {};
            }
        }
        return res;
    }

private:
    vector<int> res;
};
