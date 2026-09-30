class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            postfix *= nums[i + 1];
            res[i] *= postfix;
        }
        return res;
    }
};
