class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> flag;

        int res = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            flag[s[r]]++;
            while (flag[s[r]] > 1) {
                flag[s[l++]]--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
