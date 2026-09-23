class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int i = 0 ; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }

        int res = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            int timeTaken = 0;
            for (int i = 0 ; i < piles.size(); i++) {
                timeTaken += ceil((double) piles[i] / mid);
            }
            
            if (timeTaken > h) {
                low = mid + 1;
            } else {
                res = min(res, mid);
                high = mid - 1;
            }
        }
        return res;
    }
};
