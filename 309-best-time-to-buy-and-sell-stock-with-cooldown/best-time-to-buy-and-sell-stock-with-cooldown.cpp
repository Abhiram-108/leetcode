class Solution {
    vector<vector<int>> dp;

    int help(vector<int>& prices, int index, int buy) {
        if (index >= prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        if (buy) {
            // Option 1: Buy now → -price
            // Option 2: Skip
            return dp[index][buy] = max(
                -prices[index] + help(prices, index + 1, 0),
                help(prices, index + 1, 1)
            );
        } else {
            // Option 1: Sell now → cooldown +2
            // Option 2: Skip
            return dp[index][buy] = max(
                prices[index] + help(prices, index + 2, 1),
                help(prices, index + 1, 0)
            );
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return help(prices, 0, 1);
    }
};
