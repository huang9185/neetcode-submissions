class Solution {
    int arr[46] = {0};
public:
    int climbStairs(int n) {
        if (arr[n] != 0) return arr[n];
        int res;
        if (n == 1) res = 1;
        else if (n == 2) res = 2;
        else res = climbStairs(n-1) + climbStairs(n-2);
        arr[n] = res;
        return res;

    }
};
