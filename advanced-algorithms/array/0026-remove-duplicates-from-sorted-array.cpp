class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int curr = -101;
        int res = nums.size();
        while (r < nums.size()) {
            if (curr == nums[r]) {
                res--;
                r++;
                continue;
            }

            curr = nums[r];
            nums[l++] = nums[r++];
        }
        return res;
    }
};