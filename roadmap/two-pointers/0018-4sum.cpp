class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        long long trgt = target;
        for (int i = 0 ; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[l] + nums[r];
                    cout << (sum == trgt) << endl;
                    if (l > j + 1 && nums[l] == nums[l - 1]) {
                        l++;
                        continue;
                    }

                    if (sum < trgt) {
                        l++;
                    } else if (sum > trgt) {
                        r--;
                    } else {
                        res.push_back({ nums[i], nums[j], nums[l], nums[r] });
                        l++;
                        r--;
                        while (l < r && l > j + 1 && nums[l] == nums[l - 1]) {
                            l++;
                        }
                    }
                }
            }
        }
        return res;
    }
};