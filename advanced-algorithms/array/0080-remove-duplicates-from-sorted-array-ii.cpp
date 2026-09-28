class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int res = nums.size();
        int prev = -10001;

        int cnt = 0;
        while (r < nums.size()) {
            if (prev != nums[r]) {
                prev = nums[r];
                cnt = 1;
            } else {
                cnt++;
            }

            if (cnt >= 3) {
                r++;
                res--;
            } else {
                nums[l++] = nums[r++];
            }
        }
        return res;
    }
};