class Solution {
private:
    int help(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
        // both pattern and string exhausted
        if (i < 0 && j < 0)
            return 1;

        // pattern exhausted but string remains
        if (i < 0 && j >= 0)
            return 0;

        // string exhausted but pattern remains
        if (j < 0) {
            // remaining pattern must be like a*b*c*
            while (i >= 0) {
                if (p[i] == '*')
                    i -= 2;
                else
                    return 0;
            }
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // direct match or '.'
        if (p[i] == s[j] || p[i] == '.') {
            return dp[i][j] = help(i - 1, j - 1, p, s, dp);
        }

        // '*' case
        if (p[i] == '*') {
            // zero occurrence of previous char
            int zero = help(i - 2, j, p, s, dp);

            // one or more occurrences
            int many = 0;
            if (p[i - 1] == s[j] || p[i - 1] == '.') {
                many = help(i, j - 1, p, s, dp);
            }

            return dp[i][j] = zero || many;
        }

        return dp[i][j] = 0;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return help(m - 1, n - 1, p, s, dp);
    }
};
