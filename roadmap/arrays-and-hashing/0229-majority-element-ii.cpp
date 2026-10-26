class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1;
        int candidate2 = -1;
        int cntCandidate1 = 0;
        int cntCandidate2 = 0;

        for (int i = 0 ; i < nums.size(); i++) {
            if (candidate1 == nums[i]) {
                cntCandidate1++;
            } else if (candidate2 == nums[i]) {
                cntCandidate2++;
            } else if (cntCandidate1 == 0) {
                candidate1 = nums[i];
                cntCandidate1++;
            } else if (cntCandidate2 == 0) {
                candidate2 = nums[i];
                cntCandidate2++;
            } else {
                cntCandidate1--;
                cntCandidate2--;
            }
        }

        cntCandidate1 = 0;
        cntCandidate2 = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                cntCandidate1++;
            } else if (nums[i] == candidate2) {
                cntCandidate2++;
            }
        }

        vector<int> res;
        if (cntCandidate1 > nums.size() / 3) {
            res.push_back(candidate1);
        }

        if (cntCandidate2 > nums.size() / 3) {
            res.push_back(candidate2);
        }
        return res;
    }
};