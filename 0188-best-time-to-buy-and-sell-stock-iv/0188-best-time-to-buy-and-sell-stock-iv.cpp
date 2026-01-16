class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int i, int buy, int cap, vector<int>& prices) {
        if (i == prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;

        if (buy) {
            profit = max(
                -prices[i] + solve(i+1, 0, cap, prices), 
                 solve(i+1, 1, cap, prices)            
            );
        } else {
            profit = max(
                prices[i] + solve(i+1, 1, cap-1, prices), 
                solve(i+1, 0, cap, prices)              
            );
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

      
      

        dp.assign(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices);
    }
};
