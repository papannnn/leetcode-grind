class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        bool dupe = false;
        for (int i = 0 ; i < nums.size(); i++) {
            dupe |= s.find(nums[i]) != s.end();
            s.insert(nums[i]);
        }
        return dupe;
    }
};