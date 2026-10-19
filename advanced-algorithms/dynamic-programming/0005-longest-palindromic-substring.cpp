class Solution {
public:
    string longestPalindrome(string s) {
        int lenMax = 1;
        int resL = 0;
        int resR = 0;
        for (int i = 0 ; i < s.size(); i++) {
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                int len = r - l + 1;
                if (lenMax < len) {
                    lenMax = len;
                    resL = l;
                    resR = r;
                }

                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                int len = r - l + 1;
                if (lenMax < len) {
                    lenMax = len;
                    resL = l;
                    resR = r;
                }

                l--;
                r++;
            }
        }
        
        string res = "";
        for (int i = resL ; i <= resR; i++) {
            res += s[i];
        }
        
        return res;
    }
};
