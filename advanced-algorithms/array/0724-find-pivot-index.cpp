class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixLeft(nums.size());
        vector<int> prefixRight(nums.size());

        for (int i = 1 ; i < nums.size(); i++) {
            prefixLeft[i] = prefixLeft[i - 1] + nums[i - 1];
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            prefixRight[i] = prefixRight[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (prefixLeft[i] == prefixRight[i]) {
                return i;
            }
        }

        return -1;
    }
};