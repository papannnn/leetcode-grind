class Solution {
public:
    
    bool isPalindrome(string& s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void traverse(int idx, int tot, vector<string>& arr, string temp, string& s) {
        if (idx == s.size()) {
            if (tot == s.size())
                res.push_back(arr);
            return;
        }

        temp += s[idx];
        if (isPalindrome(temp)) {
            arr.push_back(temp);
            traverse(idx + 1, tot + temp.size(), arr, "", s);
            arr.pop_back();
        }

        traverse(idx + 1, tot, arr, temp, s);
    }

    vector<vector<string>> partition(string s) {
        vector<string> arr;
        traverse(0, 0, arr, "", s);
        return res;
    }

private:
    vector<vector<string>> res;
};
