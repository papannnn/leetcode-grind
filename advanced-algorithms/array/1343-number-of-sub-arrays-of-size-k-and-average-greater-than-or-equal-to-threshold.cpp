class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        deque<int> window;
        double tot = 0;

        int l = 0;
        int res = 0;
        for (int r = 0; r < arr.size(); r++) {
            window.push_back(arr[r]);
            tot += arr[r];

            if (r - l + 1 > k) {
                tot -= window.front();
                window.pop_front();
                l++;
            }
            
            if (tot / k >= static_cast<double>(threshold) && r - l + 1 == k) {
                res++;
            }
        }
        return res;
    }
};