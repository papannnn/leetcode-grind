class Solution {
public:

    void traverse(int idx, vector<int>& nums, vector<int>& curr) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        traverse(idx + 1, nums, curr);
        curr.pop_back();
        traverse(idx + 1, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        traverse(0, nums, curr);
        return res;
    }

private:
    vector<vector<int>> res;
};
