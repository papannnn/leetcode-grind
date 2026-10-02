class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if (slow == fast) {
                break;
            }
        }

        int slow1 = 0;
        while (true) {
            slow = nums[slow];
            slow1 = nums[slow1];

            if (slow == slow1) {
                return slow;
            }
        }
        return -1;
    }
};
