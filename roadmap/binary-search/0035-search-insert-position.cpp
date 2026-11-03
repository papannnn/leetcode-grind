class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (nums[mid] >= target) {
                res = mid;
                r = mid - 1;
            } else {
                res = mid + 1;
                l = mid + 1;
            }
        }
        return res;
    }
};