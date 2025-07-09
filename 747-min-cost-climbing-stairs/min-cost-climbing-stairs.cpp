class Solution {
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        // Take 1 step or 2 steps from current index i
        int take1 = cost[i] + solve(i + 1, cost, dp);
        int take2 = cost[i] + solve(i + 2, cost, dp);
        
        return dp[i] = min(take1, take2);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        // You can start from step 0 or step 1
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};
