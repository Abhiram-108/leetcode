class Solution {
    private:
    int f(int index,int amount,vector<int>&a,vector<vector<int>>&dp){
        if(index==0){
            if(amount%a[0]==0)
            return amount/a[0];  
        
        return 1e9;}if(dp[index][amount]!=-1)
        return dp[index][amount];
        int not_take_case=0+f(index-1,amount,a,dp);
        int take_case=INT_MAX;
        if(a[index]<=amount)
         take_case=1+f(index,amount-a[index],a,dp);
         return  dp[index][amount]=min(take_case,not_take_case);}
public:
    int coinChange(vector<int>& a, int amount) {
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,a,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};