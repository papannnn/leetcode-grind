class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMapping;

        int sum = 0;
        int res = 0;
        prefixMapping[0] = 1;
        for (int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
            res += prefixMapping[sum - k];
            prefixMapping[sum]++;
        }

        return res;
    }
};