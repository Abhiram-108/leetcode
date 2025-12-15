class Solution {

    int help(vector<vector<int>>& grid, int i, int j1, int j2,vector<vector<vector<int>>>&dp) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary check
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return -1e9;

        // last row
        if (i == m - 1) {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value;
                if (j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += help(grid, i + 1, j1 + dj1, j2 + dj2,dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));

        return help(grid,0,0,n-1,dp);
    }
};