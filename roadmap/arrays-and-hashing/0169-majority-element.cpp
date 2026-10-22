class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int cnt = 0;

        for (int i = 0 ; i < nums.size(); i++) {
            if (cnt == 0) {
                res = nums[i];
            }

            cnt += res == nums[i] ? 1 : -1;
        }
        return res;
    }
};