class Solution {
public:

    bool traverse(int idx, int bucketIdx, vector<int>& bucket, vector<int>& nums) {
        if (bucketIdx == bucket.size()) {
            return false;
        }

        if (idx == nums.size()) {
            bool res = true;
            for (int i = 1; i < bucket.size(); i++) {
                res &= bucket[i] == bucket[0];
            }
            return res;
        }

        bool res = false;
        int val = nums[idx];
        for (int i = 0 ; i < bucket.size(); i++) {
            if (bucket[i] + val > limit) {
                continue;
            }

            bucket[i] += val;
            res |= traverse(idx + 1, i, bucket, nums);
            bucket[i] -= val;
            if (res) {
                return true;
            }

            if (bucket[i] == 0) {
                break;
            }
        }
        return res;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % k != 0) {
            return false;
        }

        limit = sum / k;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > limit) {
                return false;
            }
        }

        vector<int> bucket(k);
        return traverse(0, 0, bucket, nums);
    }

private:
    int limit{};
};