class Solution {
public:
    int traverse(int idx, int currVal, vector<int>& nums) {
        if (idx == nums.size()) {
            return currVal;
        }

        int take = traverse(idx + 1, currVal ^ nums[idx], nums);
        int skip = traverse(idx + 1, currVal, nums);
        return take + skip;
    }

    int subsetXORSum(vector<int>& nums) {
        return traverse(0, 0, nums);
    }
};