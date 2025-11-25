class Solution {
public:
    int dfs(int rem, vector<int>& coins, vector<int>& memo) {
        if (rem == 0) return 0;
        if (rem < 0) return 1e9; 
        if (memo[rem] != -1) return memo[rem];

        int ans = 1e9;
        for (int c : coins) {
            ans = min(ans, 1 + dfs(rem - c, coins, memo));
        }
        return memo[rem] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);
        int result = dfs(amount, coins, memo);
        return (result >= 1e9 ? -1 : result);
    }
};
