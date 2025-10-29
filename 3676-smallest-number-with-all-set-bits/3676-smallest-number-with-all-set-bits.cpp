class Solution {
public:
    int smallestNumber(int n) {
            long long m = 1;
    while ((1LL << m) - 1 < n) {
        m++;
    }
    return (1LL << m) - 1;
    }
};