class Solution {
public:
    int m, n, k;
    vector<vector<vector<int>>> dp;
    const int MOD = 1e9 + 7;

    int solve(int i, int j, int rem, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return 0;

       
        if (i == 0 && j == 0) {
            int newRem = (rem + grid[0][0]) % k;
            return newRem == 0;
        }

        if (dp[i][j][rem] != -1) return dp[i][j][rem];

        int newRem = (rem + grid[i][j]) % k;

        long long up   = solve(i - 1, j, newRem, grid);
        long long left = solve(i, j - 1, newRem, grid);

        return dp[i][j][rem] = (up + left) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        this->k = k;

        dp.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(m - 1, n - 1, 0, grid);
    }
};
