class Solution {
private:
    vector<vector<int>> dp;

    int f(int ind, int buy, vector<int>& prices, int fee) {
        if (ind == prices.size()) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy == 1) {
            return dp[ind][buy] = max(
                -prices[ind] + f(ind+1, 0, prices, fee), // buy
                f(ind+1, 1, prices, fee)                  // skip
            );
        } else {
            return dp[ind][buy] = max(
                prices[ind] - fee + f(ind+1, 1, prices, fee), // sell
                f(ind+1, 0, prices, fee)                      // hold
            );
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return f(0, 1, prices, fee);
    }
};
