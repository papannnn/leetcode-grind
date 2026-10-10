class Solution {
public:

    void permute(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[idx]) {
                continue;
            }
            
            swap(nums[i], nums[idx]);
            permute(idx + 1, nums);    
        }

        for (int i = nums.size() - 1; i > idx; i--) {
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        permute(0, nums);
        return res;
    }

private:
    vector<vector<int>> res;
};