class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> resArr(n + 1);
        for (int i = 1 ; i <= n; i++) {
            int ptr = 1;
            int val = 0;
            while (ptr <= i) {
                val += !!(ptr & i);
                ptr = ptr << 1;
            }

            resArr[i] = val;
        }
        return resArr;
    }
};
