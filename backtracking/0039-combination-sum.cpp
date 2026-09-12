class Solution {
public:
    void traverse(vector<int> &arr, vector<int> &nums, int sum, int target, int idx) {
        if (idx == nums.size()) {
            return;
        }

        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(arr);
            return;
        }

        if (sum + nums[idx] <= target) {
            arr.push_back(nums[idx]);
            traverse(arr, nums, sum + nums[idx], target, idx);
            arr.pop_back();
            traverse(arr, nums, sum, target, idx + 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> arr;
        traverse(arr, nums, 0, target, 0);
        return res;
    }

private:
    vector<vector<int>> res;
};
