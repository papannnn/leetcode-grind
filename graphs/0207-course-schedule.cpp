class Solution {
public:
    bool traverse(int course) {
        if (visited[course]) {
            return memo[course];
        }

        bool valid = true;
        visited[course] = true;
        for (int i = 0 ; i < mapping[course].size(); i++) {
            valid &= traverse(mapping[course][i]);
        }
        memo[course] = valid;
        return valid;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memo.resize(numCourses);
        visited.resize(numCourses);

        for (int i = 0 ; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int need = prerequisites[i][1];

            mapping[course].push_back(need);
        }

        int res = 0;
        for (int i = 0 ; i < numCourses; i++) {
            res += traverse(i);
        }

        return res == numCourses;
    }

private:
    unordered_map<int, vector<int>> mapping;
    vector<bool> visited;
    vector<bool> memo;
};
