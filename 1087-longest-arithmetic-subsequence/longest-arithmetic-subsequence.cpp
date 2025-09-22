class Solution {
    int n;
    vector<vector<int>> dp;

    int help(int index, int diff, vector<int>& nums) {
        int d = diff + 500; // shift to avoid negative indices
        if (index < 0) return 0;

        if (dp[index][d] != -1)
            return dp[index][d];

        int ans = 0;
        for (int j = index - 1; j >= 0; j--) {
            if (nums[index] - nums[j] == diff)
                ans = max(ans, 1 + help(j, diff, nums));
        }

        return dp[index][d] = ans;
    }

public:
    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        if (n <= 2) return n;

        dp.assign(n, vector<int>(1001, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                ans = max(ans, 2 + help(i, diff, nums));
            }
        }

        return ans;
    }
};
