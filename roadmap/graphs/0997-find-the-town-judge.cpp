class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustOut(n + 1);
        vector<int> trustIn(n + 1);
        for (int i = 0 ; i < trust.size(); i++) {
            trustOut[trust[i][0]]++;
            trustIn[trust[i][1]]++;
        }

        int judge = -1;
        for (int i = 1 ; i <= n; i++) {
            if (trustOut[i] == 0 && trustIn[i] == n - 1) {
                judge = i;
            }
        }
        return judge;
    }
};