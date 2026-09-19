class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ptr1 = 1;
        for (int i = 0; i < 31; i++) {
            ptr1 = ptr1 << 1;
        }

        uint32_t ptr2 = 1;
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            if ((ptr2 & n)) {
                result |= ptr1;
            }

            ptr1 = ptr1 >> 1;
            ptr2 = ptr2 << 1;
        }
        
        return result;
    }
};
