class Solution {
public:
    long long solve(int i, int amount, vector<int>& coins, vector<vector<long long>>& dp) {
        if (amount == 0) return 1;              // 1 way: choose nothing more
        if (i == coins.size()) return 0;        // no coins left
        if (dp[i][amount] != -1) return dp[i][amount];

        long long ways = 0;

        // take coin[i] if possible
        if (coins[i] <= amount)
            ways += solve(i, amount - coins[i], coins, dp);

        // skip coin[i]
        ways += solve(i + 1, amount, coins, dp);

        return dp[i][amount] = ways;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<long long>> dp(coins.size(), vector<long long>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }
};
