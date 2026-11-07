class Solution {
public:
    string minWindow(string s, string t) {
        int resL = 0;
        int resR = 0;
        int resLen = 0;
        unordered_map<char, int> cntMapping;
        for (int i = 0 ; i < t.size(); i++) {
            cntMapping[t[i]]++;
        }

        int cnt = cntMapping.size();
        int l = 0;
        bool valid = false;
        for (int r = 0; r < s.size(); r++) {
            if (cntMapping.find(s[r]) != cntMapping.end()) {
                cntMapping[s[r]]--;
                if (cntMapping[s[r]] == 0) {
                    cnt--;
                }
            }

            while (cnt == 0) {
                if (!valid || resLen > r - l + 1) {
                    valid = true;
                    resLen = r - l + 1;
                    resL = l;
                    resR = r;
                }
                if (cntMapping.find(s[l]) != cntMapping.end()) {
                    cntMapping[s[l]]++;
                    if (cntMapping[s[l]] > 0) {
                        cnt++;
                    }
                }
                l++;
            }
        }
        
        return valid ? string(s.begin() + resL, s.begin() + resR + 1) : "";
    }
};
