class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> memo(nums.size());

        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        
        return memo.back();
    }
};
