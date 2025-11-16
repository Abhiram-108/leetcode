class Solution {

    int help(vector<vector<int>>& dp, vector<vector<int>>& triangle, int i, int j) {
        
        // invalid triangle positions
        if (i < 0 || j < 0 || j > i)
            return 1e9;
        
        // base case
        if (i == 0 && j == 0)
            return triangle[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        // two valid parents
        int up      = triangle[i][j] + help(dp, triangle, i-1, j);
        int upLeft  = triangle[i][j] + help(dp, triangle, i-1, j-1);

        return dp[i][j] = min(up, upLeft);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, help(dp, triangle, n-1, j));
        }

        return ans;
    }
};
