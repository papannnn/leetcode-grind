class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> resMapping;
        for (int i = 0 ; i < strs.size(); i++) {
            vector<int> cnt(26);
            for (int j = 0; j < strs[i].size(); j++) {
                cnt[strs[i][j] - 'a']++;
            }

            resMapping[cnt].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto &m : resMapping) {
            res.push_back({});
            for (int i = 0 ; i < m.second.size(); i++) {
                res.back().push_back(m.second[i]);
            }
        }
        return res;
    }
};
