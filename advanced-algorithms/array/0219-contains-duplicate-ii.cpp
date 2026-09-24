class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        deque<int> q;
        unordered_set<int> s;
        int l = 0;
        for (int r = 0 ; r < nums.size(); r++) {
            if (r - l > k) {
                s.erase(q.front());
                q.pop_front();
                l++;
            }

            if (s.find(nums[r]) != s.end()) {
                return true;
            }

            q.push_back(nums[r]);
            s.insert(nums[r]);
        }
        return false;
    }
};