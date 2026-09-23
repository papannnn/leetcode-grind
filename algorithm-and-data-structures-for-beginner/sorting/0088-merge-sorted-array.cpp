class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = nums1.size() - 1;
        int arrPtr1 = m - 1;
        int arrPtr2 = n - 1;

        while (arrPtr1 >= 0 && arrPtr2 >= 0) {
            if (nums1[arrPtr1] > nums2[arrPtr2]) {
                nums1[ptr--] = nums1[arrPtr1--];
            } else {
                nums1[ptr--] = nums2[arrPtr2--]; 
            }
        }

        while (arrPtr1 >= 0) {
            nums1[ptr--] = nums1[arrPtr1--];
        }

        while (arrPtr2 >= 0) {
            nums1[ptr--] = nums2[arrPtr2--];
        }
    }
};