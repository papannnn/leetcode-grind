class Solution {
public:
    int topDown(vector<int>& nums, vector<int>& memo, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (memo[idx] != -1) {
            return memo[idx];
        }

        int skip = topDown(nums, memo, idx + 1);
        int take = topDown(nums, memo, idx + 2) + nums[idx];
        memo[idx] = max(skip, take);
        return memo[idx];
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return topDown(nums, memo, 0);   
    }
};
