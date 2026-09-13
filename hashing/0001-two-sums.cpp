class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        for (int i = 0 ; i < nums.size(); i++) {
            if (mapping.find(nums[i]) != mapping.end()) {
                return {mapping[nums[i]], i};
            }
            mapping[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};
