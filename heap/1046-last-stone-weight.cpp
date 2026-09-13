class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0 ; i < stones.size(); i++) {
            q.push(stones[i]);
        }

        while (q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();

            if (x == y) {
                continue;
            }

            q.push(abs(x - y));
        }
        
        return q.empty() ? 0 : q.top();
    }
};
