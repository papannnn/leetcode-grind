class Solution {
public:
    void traverse(int idx, int tot, vector<int>& arr, vector<int>& candidates, int target) {
        if (tot == target) {
            res.push_back(arr);
            return;
        }

        if (idx == candidates.size() || tot > target) {
            return;
        }

        arr.push_back(candidates[idx]);
        traverse(idx + 1, tot + candidates[idx], arr, candidates, target);
        arr.pop_back();

        while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
            idx++;
        }

        traverse(idx + 1, tot, arr, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> arr;
        traverse(0, 0, arr, candidates, target);
        return res;
    }

private:
    vector<vector<int>> res;
};
