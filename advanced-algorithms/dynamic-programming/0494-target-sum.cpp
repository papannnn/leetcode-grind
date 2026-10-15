class Solution {
public:

    int traverse(int idx, vector<int>& nums, vector<unordered_map<int, int>>& memo, int curr, int target) {
        if (idx == nums.size()) {
            return curr == target;
        }

        if (memo[idx].find(curr) != memo[idx].end()) {
            return memo[idx][curr];
        }

        int subtract = traverse(idx + 1, nums, memo, curr - nums[idx], target);
        int plus = traverse(idx + 1, nums, memo, curr + nums[idx], target);

        memo[idx][curr] = subtract + plus;

        return memo[idx][curr];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> memo(nums.size());
        return traverse(0, nums, memo, 0, target);
    }
};
