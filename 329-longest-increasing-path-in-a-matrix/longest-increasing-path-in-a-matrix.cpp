class Solution {
    int help(vector<vector<int>>& a, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) return dp[i][j];  // already computed

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        int current = 1; // length starting from this cell

        for (int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];

            // check boundaries
            if (r < 0 || r >= a.size() || c < 0 || c >= a[0].size())
                continue;

            // move only if strictly increasing
            if (a[r][c] > a[i][j]) {
                current = max(current, 1 + help(a, r, c, dp));
            }
        }
        return dp[i][j] = current;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxi = max(maxi, help(a, i, j, dp));
            }
        }
        return maxi;
    }
};
