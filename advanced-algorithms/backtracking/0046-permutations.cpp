class Solution {
public:

    void traverse(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            traverse(idx + 1, nums);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        traverse(0, nums);
        return res;
    }

private:
    vector<vector<int>> res;
};
