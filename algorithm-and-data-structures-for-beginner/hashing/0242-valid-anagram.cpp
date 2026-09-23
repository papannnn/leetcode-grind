class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mapping1(26);
        vector<int> mapping2(26);

        for (int i = 0 ; i < s.length(); i++) {
            mapping1[s[i] - 'a']++;
        }

        for (int i = 0 ; i < t.length(); i++) {
            mapping2[t[i] - 'a']++;
        }

        bool valid = true;
        for (int i = 0 ; i < 26; i++) {
            valid &= mapping1[i] == mapping2[i];
        }
        return valid;
    }
};
