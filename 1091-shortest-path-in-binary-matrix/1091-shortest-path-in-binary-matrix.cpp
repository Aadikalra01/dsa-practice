class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // edge cases
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // 8 directions
        int dx[8] = {1,1,1,0,0,-1,-1,-1};
        int dy[8] = {1,0,-1,1,-1,1,0,-1};

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;  // mark visited
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n-1 && y == n-1)
                    return steps;

                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n
                        && grid[nx][ny] == 0) {

                        grid[nx][ny] = 1; // visited
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
