class Solution {
    int help(vector<int>& tasks, int limit, vector<vector<int>>& dp, int n, int mask, int curr) {
        if (mask == ((1 << n) - 1)) return 1; // all tasks completed

        if (dp[mask][curr] != -1) return dp[mask][curr];

        int res = 1e9;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) continue; // already taken

            int newMask = mask | (1 << i);

            if (curr + tasks[i] <= limit) {
                res = min(res, help(tasks, limit, dp, n, newMask, curr + tasks[i]));
            } else {
                res = min(res, 1 + help(tasks, limit, dp, n, newMask, tasks[i]));
            }
        }

        return dp[mask][curr] = res;
    }

public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<vector<int>> dp(1 << n, vector<int>(sessionTime + 1, -1));
        return help(tasks, sessionTime, dp, n, 0, 0);
    }
};
