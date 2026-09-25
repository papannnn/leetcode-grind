class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size() + 1;

        int l = 0;
        int tot = 0;
        for (int r = 0; r < nums.size(); r++) {
            tot += nums[r];
            while (tot >= target) {
                res = min(res, r - l + 1);
                tot -= nums[l++];
            }
        }
        
        if (res == nums.size() + 1) {
            return 0;
        }
        return res;
    }
};