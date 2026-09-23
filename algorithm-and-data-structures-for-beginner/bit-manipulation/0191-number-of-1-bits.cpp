class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t ptr = 1;
        int res = 0;
        for (int i = 1; i < 32; i++) {
            res += !!(ptr & n);
            ptr = ptr << 1;
        }
        return res;
    }
};
