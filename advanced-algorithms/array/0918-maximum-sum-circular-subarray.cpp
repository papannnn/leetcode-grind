class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax = nums[0];
        int globalMin = nums[0];
        int total = nums[0];
        
        int currMax = nums[0];
        int currMin = nums[0];
        for (int i = 1 ; i < nums.size(); i++) {
            currMax = max(currMax, 0);
            currMax += nums[i];

            currMin = min(currMin, 0);
            currMin += nums[i];

            total += nums[i];
            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }

        if (globalMax < 0) {
            return globalMax;
        }
        return max(globalMax, total - globalMin);
    }
};