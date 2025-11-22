class Solution {
public:
    int dp[201][201];  // matrix size max 200

    int solve(int i, int j, vector<vector<int>>& grid, int n) {
        // Out of bounds
        if(j < 0 || j >= n) return INT_MAX;

        // Base row
        if(i == n - 1) return grid[i][j];

        // Memo check
        if(dp[i][j] != -1) return dp[i][j];

        int down        = solve(i + 1, j, grid, n);
        int downLeft    = solve(i + 1, j - 1, grid, n);
        int downRight   = solve(i + 1, j + 1, grid, n);

        return dp[i][j] = grid[i][j] + min({down, downLeft, downRight});
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));

        int ans = INT_MAX;

       
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(0, j, grid, n));
        }

        return ans;
    }
};
