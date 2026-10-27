class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(l + 1, r, s) || isPalindrome(l, r - 1, s);
            }

            l++;
            r--;
        }
        return true;
    }

private:
    bool isPalindrome(int l, int r, string& s) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
};