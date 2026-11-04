class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0;
        int l = 0;
        for (int i = 0 ; i < weights.size(); i++) {
            r += weights[i];
            l = max(l, weights[i]);
        }

        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int ship = 1;
            int cargo = mid;
            for (int i = 0; i < weights.size(); i++) {
                if (cargo < weights[i]) {
                    cargo = mid;
                    ship++;
                }

                cargo -= weights[i];
            }

            if (ship > days) {
                l = mid + 1;
            } else {
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};