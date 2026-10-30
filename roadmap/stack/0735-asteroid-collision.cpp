class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        
        int idx = 0;
        while (idx < asteroids.size()) {
            if (stk.empty()) {
                stk.push_back(asteroids[idx++]);
                continue;
            }

            int asteroid = asteroids[idx];
            if (stk.back() > 0 && asteroid > 0) {
                stk.push_back(asteroids[idx++]);
                continue;
            }

            if (stk.back() < 0) {
                stk.push_back(asteroids[idx++]);
                continue;
            }

            if (stk.back() < abs(asteroid)) {
                stk.pop_back();
            } else if (stk.back() == abs(asteroid)) {
                stk.pop_back();
                idx++;
            } else {
                idx++;
            }
        }
        return stk;
    }
};