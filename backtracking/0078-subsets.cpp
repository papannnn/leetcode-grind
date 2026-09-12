class Solution {
public:
    void traverse(vector<int> &arr, vector<int>& num, int idx) {
        for (int i = idx; i < num.size(); i++) {
            arr.push_back(num[i]);
            traverse(arr, num, i + 1);
            arr.pop_back();
        }
        res.push_back(arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        traverse(arr, nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
};
