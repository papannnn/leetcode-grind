class Solution {
public:

    void traverse(int idx, vector<int>& nums, vector<int>& curr, int tot, int target) {
        if (tot == target) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (tot + nums[i] > target) {
                continue;
            }

            curr.push_back(nums[i]);
            traverse(i, nums, curr, tot + nums[i], target);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        traverse(0, nums, curr, 0, target);
        return res;
    }

private:
    vector<vector<int>> res;
};
