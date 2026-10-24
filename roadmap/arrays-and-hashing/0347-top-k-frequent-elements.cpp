class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int i = 0 ; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        vector<vector<int>> mapping(10001);
        for (auto &m : cnt) {
            mapping[m.second].push_back(m.first);
        }

        vector<int> res;
        for (int i = mapping.size() - 1; i >= 0 && k; i--) {
            for (int j = 0; j < mapping[i].size() && k; j++) {
                cout << i << endl;
                res.push_back(mapping[i][j]);
                k--;
            }
        }
        return res;
    }
};
