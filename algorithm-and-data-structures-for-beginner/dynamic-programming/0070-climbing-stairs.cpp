class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr(n + 1);
        arr[n - 1] = 1;
        if (n - 2 >= 0) {
            arr[n - 2] = 2;
        }
        
        for (int i = n - 3; i >= 0; i--) {
            arr[i] = arr[i + 1] + arr[i + 2];
        }
        return arr[0];
    }
};
