class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        deque<int> q;

        vector<int> res;
        while (r < nums.size()) {
            while (!q.empty() && q.back() < nums[r]) {
                q.pop_back();
            }
            q.push_back(nums[r]);

            if (r - l + 1 < k) {
                r++;
                continue;
            }

            while (r - l + 1 > k) {
                if (!q.empty() && nums[l] == q.front()) {
                    q.pop_front();
                }
                l++;
            }
            res.push_back(q.front());
            r++;
        }   
        return res;
    }
};
