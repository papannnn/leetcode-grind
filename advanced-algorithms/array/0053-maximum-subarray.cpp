class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currVal = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currVal = max(currVal, 0);
            currVal += nums[i];
            result = max(result, currVal);
        }
        return result;
    }
};
