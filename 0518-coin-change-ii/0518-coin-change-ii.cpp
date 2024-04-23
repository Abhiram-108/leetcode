class Solution {
    private:
    int f(int index,int amount,vector<vector<int>>&dp,vector<int>&coins){
        if(index==0){
            if(amount % coins[index] ==0)
                return 1;
            return 0;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int nottake=0+f(index-1,amount,dp,coins);
        int take=0;
        if(coins[index]<=amount)
        take=f(index,amount-coins[index],dp,coins);
        return dp[index][amount]=nottake+take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,dp,coins);
        
    }
};