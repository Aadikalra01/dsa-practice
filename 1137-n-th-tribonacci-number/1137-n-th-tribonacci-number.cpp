class Solution {
public:
    int tribonacci(int n) {
         if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    long long a = 0, b = 1, c = 1;
    long long curr = 0;

    for (int i = 3; i <= n; i++) {
        curr = a + b + c;  // T(n-1) + T(n-2) + T(n-3)
        a = b;
        b = c;
        c = curr;
    }

    return c;
    }
};