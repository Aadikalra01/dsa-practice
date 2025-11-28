class Solution {
public:
    string maximumOddBinaryNumber(string s) {
      int ones = 0, zeros = 0;

    // Count ones and zeros
    for (char c : s) {
        if (c == '1') ones++;
        else zeros++;
    }

    // Reserve one '1' for the last position
    int frontOnes = ones - 1;

    string ans(s.size(), '0');

    int idx = 0;

    // Fill front with ones (except last one)
    while (frontOnes > 0) {
        ans[idx++] = '1';
        frontOnes--;
    }

    // Fill zeros
    while (zeros > 0) {
        ans[idx++] = '0';
        zeros--;
    }

    // Last position must be '1'
    ans.back() = '1';

    return ans;
    }
};