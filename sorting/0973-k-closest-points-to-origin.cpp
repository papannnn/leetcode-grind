class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [] (const vector<int>&a, const vector<int>&b) {
            double varA = sqrt(a[0] * a[0] + a[1] * a[1]);
            double varB = sqrt(b[0] * b[0] + b[1] * b[1]);
            return varA < varB;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q;
        for (int i = 0 ; i < points.size(); i++) {
            q.push(points[i]);
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }

        return res;
    }
};
