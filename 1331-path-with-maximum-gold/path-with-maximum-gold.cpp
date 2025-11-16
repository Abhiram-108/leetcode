class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        int gold = grid[i][j];
        grid[i][j] = 0;     // mark visited

        int best = 0;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            best = max(best, dfs(grid, i + dr[k], j + dc[k]));
        }

        grid[i][j] = gold;  // backtrack (restore)
        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};
