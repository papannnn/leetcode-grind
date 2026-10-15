struct Binary {
    int zero;
    int one;
};

class Solution {
public:

    int traverse(int idx, vector<Binary>& arr, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& memo, int m, int n) {
        if (idx == arr.size()) {
            return 0;
        }

        if (memo.find(idx) != memo.end() && memo[idx].find(m) != memo[idx].end() && memo[idx][m].find(n) != memo[idx][m].end()) {
            return memo[idx][m][n];
        }

        int skip = traverse(idx + 1, arr, memo, m, n);
        int take = 0;
        if (arr[idx].zero <= m && arr[idx].one <= n) {  
            take = 1 + traverse(idx + 1, arr, memo, m - arr[idx].zero, n - arr[idx].one);
        }
        
        memo[idx][m][n] = max(take, skip);
        return memo[idx][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<Binary> arr;
        for (int i = 0 ; i < strs.size(); i++) {
            int zero = 0;
            int one = 0;
            for (int j = 0 ; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    zero++;
                } else {
                    one++;
                }
            }

            arr.push_back({ zero, one });
        }

        unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;
        return traverse(0, arr, memo, m, n);
    }
};