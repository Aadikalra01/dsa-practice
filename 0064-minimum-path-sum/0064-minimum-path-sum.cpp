class Solution {
public:
    int dp[201][201];

    int solve(int i ,int j , int m ,int n, vector<vector<int>>& grid){
        if(i >= m || j >= n) return INT_MAX;   // out of bounds
        if(i == m-1 && j == n-1) return grid[i][j]; // last cell
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i+1, j, m, n, grid);
        int right = solve(i, j+1, m, n, grid);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m, n, grid);
    }
};