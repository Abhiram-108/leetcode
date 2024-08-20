class Solution {
    private:
    int f(vector<int>&s,int i,vector<int>&dp){
        if(i>=s.size())
            return 0;
        else if(dp[i]!=-1)
            return dp[i];
        else{
        int ans=INT_MIN;
        ans=max(ans,s[i]-f(s,i+1,dp));
        if(i+1<s.size())
            ans=max(ans,s[i]+s[i+1]-f(s,i+2,dp));
        if(i+2<s.size())
            ans=max(ans,s[i]+s[i+1]+s[i+2]-f(s,i+3,dp));
        return dp[i]=ans;}
    }
public:
    string stoneGameIII(vector<int>& s) {
        vector<int>dp(50001,-1);
        int alice=f(s,0,dp);
        if(alice>0)
            return "Alice";
        else if(alice==0)
            return "Tie";
        else
            return "Bob";
    }
    
};