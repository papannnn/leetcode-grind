class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int maxVal = 0;
        for (int i = 0 ; i < people.size(); i++) {
            maxVal = max(maxVal, people[i]);
        }

        vector<int> cnt(maxVal + 1);
        for (int i = 0 ; i < people.size(); i++) {
            cnt[people[i]]++;
        }

        vector<int> peopleSorted(people.size());
        int curr = 1;
        for (int i = 0; i < peopleSorted.size(); i++) {
            while (cnt[curr] == 0) {
                curr++;
            }

            peopleSorted[i] = curr;
            cnt[curr]--;
        }

        int l = 0;
        int r = peopleSorted.size() - 1;
        int res = 0;
        while (l <= r) {
            int tot = peopleSorted[l] + peopleSorted[r];
            if (tot > limit) {
                r--;
            } else {
                r--;
                l++;
            }
            res++;
        }

        return res;
    }
};