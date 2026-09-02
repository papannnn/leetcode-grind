class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        
        if (memo[n]) {
            return memo[n];
        }
        memo[n] = climbStairs(n - 2) + climbStairs(n - 1);
        return memo[n];
    }
private:
    array<int, 46> memo;
};
