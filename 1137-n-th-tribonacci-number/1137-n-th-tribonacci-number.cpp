class Solution {
    private:
    int  f(int n,vector<int>&dp){
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]= f(n-1,dp)+f(n-2,dp)+f(n-3,dp);
    }
public:
    int tribonacci(int n) {
        vector<int>dp(38,-1);
        return f(n,dp);
        
    }
};