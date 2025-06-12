class Solution {

    private:
    int help(vector<int>&prices,vector<vector<vector<int>>>&dp,int index,int buy,int cap){
        if(index>=prices.size())
        return 0;
        if(cap==0)
        return 0;
        if(dp[index][buy][cap]!=-1)
        return dp[index][buy][cap];

        if(buy)
        return dp[index][buy][cap]=max(-prices[index]+help(prices,dp,index+1,0,cap) ,help(prices,dp,index+1,1,cap));

        else
        return dp[index][buy][cap]=max(prices[index]+help(prices,dp,index+1,1,cap-1),help(prices,dp,index+1,0,cap));




    }
public:
    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return help(prices,dp,0,1,k);
        
    }
};