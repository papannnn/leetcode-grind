class Solution {
public:

    bool traverse(int idx, vector<int>& nums, vector<vector<int>>& memo, int sum) {
        if (idx == nums.size()) {
            return false;
        }

        if (memo[idx][sum] != -1) {
            return memo[idx][sum];
        }

        if (sum == target) {
            return true;
        }

        if (sum > target) {
            return false;
        }

        bool skip = traverse(idx + 1, nums, memo, sum);
        bool take = traverse(idx + 1, nums, memo, sum + nums[idx]);
        memo[idx][sum] = skip || take;
        return memo[idx][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        target = sum / 2;

        vector<vector<int>> memo(nums.size(), vector<int>(sum + 1, -1));
        return traverse(0, nums, memo, 0);
    }

private:
    bool res{false};
    int target{};
};
