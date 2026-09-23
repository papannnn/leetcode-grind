class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                counter++;
            } else {
                counter = 0;
            }
            res = max(res, counter);
        }
        return res;
    }
};