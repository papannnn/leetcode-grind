class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cntLetter(26);
        int cnt = s1.size();
        for (int i = 0 ; i < s1.size(); i++) {
            cntLetter[s1[i] - 'a']++; 
        }

        int l = 0;
        for (int r = 0; r < s2.size() && cnt; r++) {
            cntLetter[s2[r] - 'a']--;
            cnt--;
            while (cntLetter[s2[r] - 'a'] < 0) {
                cntLetter[s2[l] - 'a']++;
                l++;
                cnt++;
            }

            if (cnt == 0) {
                return true;
            }
        }
        return false;
    }
};
