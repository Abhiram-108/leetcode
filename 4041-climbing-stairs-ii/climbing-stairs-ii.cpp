class Solution {

    int help(int i, vector<int>& costs, vector<int>& dp) {
        if (i > costs.size())
            return 1e9;

         if(i==costs.size())
         return costs[i-1];   

        if (dp[i] != -1)
            return dp[i];

       int ans= i-1>=0 ? costs[i-1] : 0;   

        int take1 =  1 + help(i + 1, costs, dp);
        int take2 =  4 + help(i + 2, costs, dp);
        int take3 =  9 + help(i + 3, costs, dp);

        return dp[i] = min(take1, min(take2, take3)) + ans;;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, -1);
        return help(0, costs, dp);
    }
};
