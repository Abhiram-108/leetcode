class Solution {
    int help(vector<int>&prices,int fee,vector<vector<int>>&dp,int index,int buy){
        if(index==prices.size())
        return 0;
        if(dp[index][buy]!=-1)
        return dp[index][buy];

        if(buy){
           return dp[index][buy]=max(-prices[index]+help(prices,fee,dp,index+1,0) , help(prices,fee,dp,index+1,1));
        }
        else{
           return dp[index][buy]=max(prices[index]-fee+help(prices,fee,dp,index+1,1) , help(prices,fee,dp,index+1,0));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(prices,fee,dp,0,1);
        
    }
};