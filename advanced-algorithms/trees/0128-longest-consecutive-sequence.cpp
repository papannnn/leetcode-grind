

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;

        for (int i = 0 ; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (numSet.find(nums[i] - 1) == numSet.end()) {
                int len = 0;
                while (numSet.find(nums[i] + len) != numSet.end()) {
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};
